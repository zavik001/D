import java.util.Scanner;
import java.util.HashMap;

public class BookingScheduler {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashMap<String, Integer> dayToIndex = new HashMap<>();
        dayToIndex.put("MON", 0);
        dayToIndex.put("TUE", 1);
        dayToIndex.put("WED", 2);
        dayToIndex.put("THU", 3);
        dayToIndex.put("FRI", 4);
        dayToIndex.put("SAT", 5);
        dayToIndex.put("SUN", 6);

        boolean[] isOccupied = new boolean[28];
            
        for (int week = 0; week < 4; week++) {
            String line = scanner.nextLine().trim();
            if (!line.isEmpty()) {
                String[] occupiedDays = line.split(" ");
                for (String day : occupiedDays) {
                    int dayOfWeek = dayToIndex.get(day);
                    int dayOfMonth = week * 7 + dayOfWeek;
                    isOccupied[dayOfMonth] = true;
                }
            }
        }
        
        int maxFreeStart = 0;
        int maxFreeEnd = 0;
        int currentFreeStart = -1;
        int currentFreeLength = 0;
        int maxFreeLength = 0;

        for (int i = 0; i < 28; i++) {
            if (!isOccupied[i]) {
                if (currentFreeStart == -1) {
                    currentFreeStart = i;
                }
                currentFreeLength++;
            } else {
                if (currentFreeLength > maxFreeLength) {
                    maxFreeLength = currentFreeLength;
                    maxFreeStart = currentFreeStart;
                    maxFreeEnd = i - 1;
                }
                currentFreeStart = -1;
                currentFreeLength = 0;
            }
        }

        if (currentFreeLength > maxFreeLength) {
            maxFreeLength = currentFreeLength;
            maxFreeStart = currentFreeStart;
            maxFreeEnd = 27;
        }

        if (maxFreeLength == 0) {
            System.out.println("0 0");
        } else {
            System.out.println((maxFreeStart + 1) + " " + (maxFreeEnd + 1));
        }

        scanner.close();
    }
}