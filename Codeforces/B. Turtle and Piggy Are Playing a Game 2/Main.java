import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int t = input.nextInt();
        for (; t > 0; t--) {
            int n = input.nextInt();
            int ans = 0;
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = input.nextInt();
            }

            Arrays.sort(arr);
            int a1, a2;
            if (n % 2 == 0) {
                a1 = arr[n/2];
                a2 = arr[n/2-1];
                ans = Math.max(a1, a2);
            } else {
                a1 = arr[n/2];
                a2 = arr[n/2 + 1];
                ans = Math.min(a1, a2);
            }

            System.out.println(ans);
        }
        input.close();
    }
}