import java.util.*;
public class SockCounter {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        long res = 0;
        int n = input.nextInt();
        for (int i = 0; i < n; i++) {
            long a = input.nextLong();
            res += a % 2;
        }
        input.close();

        if (res % 2 == 0) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}