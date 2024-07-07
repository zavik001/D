import java.util.*;

public class BasilGarden {
   public static void print(long x) {
      System.out.println(x);
   }

   public static long MinSec(int[] arr) {
      int n = arr.length;
      long minSecTree = 0;

      for (int i = n - 1; i >= 0; i--) {
         minSecTree = Math.max(minSecTree, arr[i] + i);
      }

      return minSecTree;
   }
   public static void main(String[] args) {
      Scanner input = new Scanner(System.in);

      int t = input.nextInt();
      for (int i = 0; i < t; i++) {
         int n = input.nextInt();
         int[] h = new int[n];
         for (int j = 0; j < n; j++) {
            h[j] = input.nextInt();
         }
   
         print(MinSec(h));
      }
      input.close();
   }
}
