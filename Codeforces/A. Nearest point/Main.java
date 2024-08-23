import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int t = input.nextInt();
        for (; t > 0; t--) {
            int n = input.nextInt();

            int[] arr = new int[n];

            for (int i = 0; i < n; i++) {
                arr[i] = input.nextInt();
            }

            if (n > 2) {
                System.out.println("NO");
            } else if (n == 2) {
                if (Math.abs(arr[0] - arr[1]) < 2) {
                    System.out.println("NO");
                } else {
                    System.out.println("YES");
                }
            } else {
                System.out.println("YES");
            }
        }

        input.close();
    }
}