import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while (t-- > 0) {
            int n = scanner.nextInt();
            int k = scanner.nextInt();
            int[] arr = new int[n];

            for (int i = 0; i < n; i++) {
                arr[i] = scanner.nextInt();
            }

            Arrays.sort(arr);
            for (int i = 0; i < arr.length / 2; i++) {
                int temp = arr[i];
                arr[i] = arr[arr.length - 1 - i];
                arr[arr.length - 1 - i] = temp;
            }
            
            for (int i = 0; i < n && k > 0; i++) {
                if (i % 2 == 1) {
                    int diff = arr[i - 1] - arr[i];
                    int increment = Math.min(diff, k);
                    arr[i] += increment;
                    k -= increment;
                }
            }

            int aliceScore = 0, bobScore = 0;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 1) {
                    aliceScore += arr[i - 1];
                    bobScore += arr[i];
                    arr[i] = 0;
                    arr[i - 1] = 0;
                } 
            }

            if (arr[n-1] > 0) {
                aliceScore += arr[n-1];
            }
            System.out.println(aliceScore - bobScore);
        }
        scanner.close();
    }
}
