import java.util.*;

public class Main {
   public static void printMinTime(int n, int k) {
      if (n == 1) {
         System.out.println(1);
      } else {
         System.out.println(k * (n - 1) + 1);
      }
   }

   public static void main(String[] args) {
      Scanner input = new Scanner(System.in);

      int t = input.nextInt();

      for (int i = 0; i < t; i++) {
         printMinTime(input.nextInt(), input.nextInt());
      }

      input.close();
   }
}
