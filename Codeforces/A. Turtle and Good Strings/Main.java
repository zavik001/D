import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int t = input.nextInt();
        for (; t > 0; t--) {
            int n = input.nextInt();
            String s = input.next();
            
            if (s.charAt(0) == s.charAt(n-1)) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }
        input.close();
    }
}