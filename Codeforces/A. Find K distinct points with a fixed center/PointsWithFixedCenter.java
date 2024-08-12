import java.util.Scanner;

public class PointsWithFixedCenter {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); 

        for (int i = 0; i < t; i++) {
            int xc = sc.nextInt();
            int yc = sc.nextInt();
            int k = sc.nextInt();

            int sumX = 0;
            int sumY = 0;

            for (int j = 1; j < k; j++) {
                int xi = xc + j; 
                int yi = yc + j; 
                System.out.println(xi + " " + yi);
                sumX += xi;
                sumY += yi;
            }

            int xk = k * xc - sumX;
            int yk = k * yc - sumY;
            System.out.println(xk + " " + yk);
        }

        sc.close();
    }
}
