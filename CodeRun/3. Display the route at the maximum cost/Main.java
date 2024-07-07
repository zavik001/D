import java.util.*;
import javafx.util.Pair;


public class Main {
    public static void printMaxWholeMeal(Pair<Integer, String> arr) {
        System.out.println(arr.getKey());
        String path = arr.getValue();
        for (int i = 0; i < path.length(); i++) {
            System.out.print(path.charAt(i));
            if (i < path.length() - 1) {
                System.out.print(" ");
            }
        }
    }

    public static Pair<Integer, String> FindMaxWholeMeal(Pair<Integer, String>[][] arr) {
        int n = arr.length;
        int m = arr[0].length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j > 0) {
                    arr[i][j] = new Pair<>(arr[i][j].getKey() + arr[i][j-1].getKey(), arr[i][j-1].getValue() + "R");
                } else if (j == 0 && i > 0) {
                    arr[i][j] = new Pair<>(arr[i][j].getKey() + arr[i-1][j].getKey(), arr[i-1][j].getValue() + "D");
                } else if (i > 0 && j > 0) {
                    int prevValue1 = arr[i-1][j].getKey();
                    int prevValue2 = arr[i][j-1].getKey();
                    if (prevValue1 > prevValue2) {
                        arr[i][j] = new Pair<>(arr[i][j].getKey() + prevValue1, arr[i-1][j].getValue() + "D");
                    } else {
                        arr[i][j] = new Pair<>(arr[i][j].getKey() + prevValue2, arr[i][j-1].getValue() + "R");
                    }
                }
            }
        }

        return arr[n-1][m-1];
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        Pair<Integer, String>[][] arr = new Pair[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = new Pair<>(input.nextInt(), "");
            }
        }

        printMaxWholeMeal(FindMaxWholeMeal(arr));

        input.close();
    }
}
