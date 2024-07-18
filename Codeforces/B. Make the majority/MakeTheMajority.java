import java.util.Scanner;

public class MakeTheMajority {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();

        for (int i = 0; i < t; i++) {
            int n = input.nextInt();
            input.nextLine();  // Пропустить оставшийся переход на новую строку после числа
            String s = input.nextLine();
            int sum0 = 0, sum1 = 0;
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == '1') {
                    sum1++;
                } else {
                    if (j == n - 1) {
                        sum0++;
                    } else {
                        if (s.charAt(j + 1) != '0') {
                            sum0++;
                        }
                    }
                }
            }

            if (sum1 > sum0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        input.close();
    }
}
