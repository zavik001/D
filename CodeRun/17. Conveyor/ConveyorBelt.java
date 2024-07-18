import java.util.*;

public class ConveyorBelt {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine();  // Переход на следующую строку после считывания числа N
        for (int i = 0; i < N; i++) {
            String line = scanner.nextLine();
            String[] parts = line.split(" ");
            int K = Integer.parseInt(parts[0]);
            double[] urgencies = new double[K];
            for (int j = 0; j < K; j++) {
                urgencies[j] = Double.parseDouble(parts[j + 1]);
            }
            System.out.println(canBeSorted(urgencies) ? 1 : 0);
        }
    }

    private static boolean canBeSorted(double[] urgencies) {
        Stack<Double> stack = new Stack<>();
        double expectedUrgency = 1.0;

        for (double urgency : urgencies) {
            // Пока верхний контейнер на складе имеет ожидаемую срочность, выталкиваем его
            while (!stack.isEmpty() && stack.peek() == expectedUrgency) {
                stack.pop();
                expectedUrgency++;
            }
            // Если текущий контейнер имеет ожидаемую срочность, сразу отправляем его в цех В
            if (urgency == expectedUrgency) {
                expectedUrgency++;
            } else {
                // Иначе кладем на склад
                stack.push(urgency);
            }
        }

        // Проверяем оставшиеся контейнеры на складе
        while (!stack.isEmpty() && stack.peek() == expectedUrgency) {
            stack.pop();
            expectedUrgency++;
        }

        // Если все контейнеры были правильно упорядочены, склад будет пустым
        return stack.isEmpty();
    }
}
