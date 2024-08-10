import java.util.Scanner;

public class CandyBuyingSimulator {
    private static long n = 0, k = 0, a = 0, m = 0;

    private static long lcg(long e) {
        return (a * e + 11) % m;
    }

    private static long generator(long seed) {
        return (Math.abs(seed % 3 - 1) * 5 + Math.abs(seed % 3) * 2) % 8;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        n = scanner.nextLong();
        k = scanner.nextLong();
        a = scanner.nextLong();
        m = scanner.nextLong();

        long seed = 0;
        int coinCount = 0;
        long totalMoney = 0;
        while (n > 0) {
            seed = lcg(seed);
            long coin = generator(seed);

            coinCount++;
            totalMoney += coin;
            
            if (totalMoney >= 3 * k) {
                n -= totalMoney / 3;
                totalMoney %= 3;
            }
        }

        System.out.println(coinCount);
        scanner.close();
    }
}