import java.util.Scanner;

public class DoorsGame {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while (t-- > 0) {
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            int L = scanner.nextInt();
            int R = scanner.nextInt();
            int answer = 0;

            if (r < L || l > R) {
                answer = 1;
            } else {
                answer = Math.min(R, r) - Math.max(L, l) + 2;
                if (l == L && r == R) {
                    answer -= 2;
                } 
                if (l != L && r == R || l == L && r != R) {
                    answer--;
                }
            }

            System.out.println(answer);
        }
    }
}
