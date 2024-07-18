import java.util.*;

public class DivideTheMultiset {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();

        for (int i = 0; i < t; i++) {
            int n = input.nextInt(), k = input.nextInt();
            int sum = 0;
            if (n != 1) {
                for (;n > 1;) {
                    n = n - (k - 1);
                    sum++;
                }
            }

            System.out.println(sum);
        }
        input.close();
    }
}