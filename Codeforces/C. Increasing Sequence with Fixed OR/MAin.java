import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt(); // количество тестов
        
        while (t-- > 0) {
            long n = scanner.nextLong(); // читаем значение n для текущего теста
            
            List<Long> longestSequence = new ArrayList<>();
            
            // Находим самую длинную последовательность
            for (int bit = 60; bit >= 0; bit--) {
                long candidate = (1L << bit) - 1;
                if ((candidate & n) == candidate) {
                    longestSequence.add(candidate);
                    n &= ~candidate; // обнуляем биты, которые уже использовали
                }
            }
            
            // Вывод результата
            System.out.println(longestSequence.size());
            for (long num : longestSequence) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}
