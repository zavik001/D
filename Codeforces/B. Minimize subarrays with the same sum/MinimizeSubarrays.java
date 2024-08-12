import java.util.Scanner;
import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class MinimizeSubarrays {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); // количество тестов

        while (t-- > 0) {
            int n = sc.nextInt();
            List<Integer> p = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                p.add(sc.nextInt());
            }

            Collections.reverse(p);

            for (int i = 0; i < n; i++) {
                System.out.print(p.get(i) + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
