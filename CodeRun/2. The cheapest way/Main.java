import java.util.*;

public class Main {

    /*
     * Для чтения входных данных необходимо получить их
     * из стандартного потока ввода (System.in).
     * Данные во входном потоке соответствуют описанному
     * в условии формату. Обычно входные данные состоят
     * из нескольких строк. Можно использовать более производительные
     * и удобные классы BufferedReader, BufferedWriter, Scanner, PrintWriter.
     * 
     * С помощью BufferedReader можно прочитать из стандартного потока:
     * строку -- reader.readLine()
     * число -- int n = Integer.parseInt(reader.readLine());
     * массив чисел известной длины (во входном потоке каждое число на новой строке)
     * --
     * int[] nums = new int[len];
     * for (int i = 0; i < len; i++) {
     * nums[i] = Integer.parseInt(reader.readLine());
     * }
     * последовательность слов в строке --
     * String[] parts = reader.readLine().split(" ");
     * 
     * Чтобы вывести результат в стандартный поток вывода (System.out),
     * Через BufferedWriter можно использовать методы
     * writer.write("Строка"), writer.write('A') и writer.newLine().
     * 
     * Возможное решение задачи "Вычислите сумму чисел в строке":
     * int sum = 0;
     * String[] parts = reader.readLine().split(" ");
     * for (int i = 0; i < parts.length; i++) {
     * int num = Integer.parseInt(parts[i]);
     * sum += num;
     * }
     * writer.write(String.valueOf(sum));
     */
    public static void printMinWholeMeal(int res) {
        System.out.print(res);
    }

    public static int FindMinWholeMeal(int[][] arr) {
        int n = arr.length;
        int m = arr[0].length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j > 0) {
                    arr[i][j] += arr[i][j - 1];
                } else if (j == 0 && i > 0) {
                    arr[i][j] += arr[i - 1][j];
                } else if (i > 0 && j > 0) {
                    arr[i][j] += Math.min(arr[i - 1][j], arr[i][j - 1]);
                }
            }
        }

        return arr[n - 1][m - 1];
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        int[][] arr = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = input.nextInt();
            }
        }

        printMinWholeMeal(FindMinWholeMeal(arr));

        input.close();
    }

}
