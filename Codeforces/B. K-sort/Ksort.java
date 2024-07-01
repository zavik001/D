import java.util.*;

public class Ksort {
   public static void printMinCoins(long x) {
      System.out.println(x);
   }

   public static long findMinCoins(int[] arr) {
      int n = arr.length;
      long max = 0;
      long totalCoins = 0;

      for (int i = 1; i < n; i++) {
         if (arr[i] < arr[i-1]) {
            int x = arr[i-1] - arr[i];
            if (x > max) {
               max = x;
            }
            totalCoins += x;
            arr [i] = arr[i-1];
         }
      }

      return totalCoins + max;
   }

   public static void main(String[] args) {
      Scanner input = new Scanner(System.in);

      int t = input.nextInt();

      for (int i = 0; i < t; i++) {
         int n = input.nextInt();
         int[] arr = new int[n];
         for (int j = 0; j < n; j++) {
            arr[j] = input.nextInt();
         }
         long coins = findMinCoins(arr);
         printMinCoins(coins);
      }

      input.close();
   }
}