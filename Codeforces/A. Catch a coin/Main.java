import java.util.*;

public class Main {
   static boolean check(int y) {
      return y >= -1;
   }

   public static void main(String[] args) {
      Scanner input = new Scanner(System.in);
      int n = input.nextInt();

      for (int i = 0; i < n; i++) {
         input.nextInt();
         int y = input.nextInt();
         if (check(y)) {
            System.out.println("YES");
         } else {
            System.out.println("NO");
         }
      }

      input.close();
   }
}