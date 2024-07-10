import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());
        if (N == 0) {
            System.out.println("0\n0 0");
            return;
        }
        
        int[] costs = new int[N];
        for (int i = 0; i < N; i++) {
            costs[i] = Integer.parseInt(reader.readLine());
        }
        
        // DP array
        int[][] dp = new int[N + 1][N + 1];
        int[][] usedCoupons = new int[N + 1][N + 1];
        int INF = Integer.MAX_VALUE / 2; // Large enough to prevent overflow
        
        // Initialize dp array
        for (int i = 0; i <= N; i++) {
            Arrays.fill(dp[i], INF);
        }
        
        dp[0][0] = 0; // Base case: 0 days, 0 coupons used -> cost is 0
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                if (dp[i][j] == INF) continue;
                
                // If we use j coupons on day i (for days 1 to N)
                if (costs[i] > 100) {
                    // Use one more coupon (j -> j + 1) and reset the cost for next day
                    if (dp[i][j] < dp[i + 1][j + 1]) {
                        dp[i + 1][j + 1] = dp[i][j];
                        usedCoupons[i + 1][j + 1] = usedCoupons[i][j];
                    }
                }
                
                // Don't use coupon (j -> j) and add the cost for next day
                if (dp[i][j] + costs[i] < dp[i + 1][j]) {
                    dp[i + 1][j] = dp[i][j] + costs[i];
                    usedCoupons[i + 1][j] = usedCoupons[i][j];
                }
            }
        }
        
        // Find minimum total cost and corresponding K1 (unused coupons)
        int minCost = INF;
        int K1 = 0;
        for (int j = 0; j <= N; j++) {
            if (dp[N][j] < minCost) {
                minCost = dp[N][j];
                K1 = j;
            }
        }
        
        // Find K2 (used coupons)
        int K2 = N - K1;
        
        // Collecting the days when coupons were used
        List<Integer> couponDays = new ArrayList<>();
        int currentJ = K1;
        for (int i = N; i > 0; i--) {
            if (costs[i - 1] > 100 && currentJ > 0 && dp[i - 1][currentJ - 1] == dp[i][currentJ] - costs[i - 1]) {
                couponDays.add(i); // Day i is 1-indexed
                currentJ--;
            }
        }
        
        // Sort coupon days in ascending order
        Collections.sort(couponDays);
        
        // Print the results
        System.out.println(minCost);
        System.out.println(K1 + " " + K2);
        for (int day : couponDays) {
            System.out.println(day);
        }
    }
}   
