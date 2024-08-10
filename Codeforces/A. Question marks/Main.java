import java.util.*;

public class Main {
    static public void main(String[] atgs) {
        Scanner input = new Scanner(System.in);

        int t = input.nextInt();

        for ( ; t > 0; t--) {
            int n = input.nextInt();
            input.nextLine();
            int[] arr = new int[4];

            String s = input.nextLine();

            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == 'A') {
                    arr[0]++;
                } else if (s.charAt(j) == 'B') {
                    arr[1]++;
                } else if (s.charAt(j) == 'C') {
                    arr[2]++;
                } else if (s.charAt(j) == 'D') {
                    arr[3]++;
                }
            }
            System.out.println(Math.min(n, arr[0]) + Math.min(n, arr[1]) +  Math.min(n, arr[2]) +  Math.min(n, arr[3]));
        }
    }
}