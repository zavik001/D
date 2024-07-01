import java.util.*;

public class BasilGarden {
   public static void print(long x) {
      System.out.println(x);
   }

   public static long MinSec(int[] arr) {
      int n = arr.length;
      long passedSec = 0;

      for (int i = n - 1; i > 0; i--) {
         if (arr[i-1] > arr[i]) {
            if (arr[i-1] == arr[i] + passedSec) {
               passedSec++;
            }
            passedSec += arr[i];
            arr[i-1] -= passedSec;
            arr[i] -= passedSec;
            if (arr[i-1] < 0) {
               arr[i-1] = 0;
            }
            if (arr[i] < 0) {
               arr[i] = 0;
            }
         } else {
            passedSec += arr[i];
            arr[i] = 0;
            arr[i - 1] = 1;
         }
      }

      if (arr[0] < 0) {
         arr[0] = 0;
      }

      return passedSec + arr[0];
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
