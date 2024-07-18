import java.util.*;

public class MetroSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(); // Количество станций
        int M = sc.nextInt(); // Количество линий

        // Список смежности для графа станций
        List<List<Integer>> graph = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        // Чтение линий и построение графа
        for (int i = 0; i < M; i++) {
            int P = sc.nextInt(); // Количество станций на линии
            int[] line = new int[P];
            for (int j = 0; j < P; j++) {
                line[j] = sc.nextInt();
            }
            // Добавление ребер между станциями на одной линии
            for (int j = 0; j < P - 1; j++) {
                for (int k = j + 1; k < P; k++) {
                    graph.get(line[j]).add(line[k]);
                    graph.get(line[k]).add(line[j]);
                }
            }
        }

        int A = sc.nextInt(); // Начальная станция
        int B = sc.nextInt(); // Конечная станция

        // Если A и B совпадают
        if (A == B) {
            System.out.println(0);
            return;
        }

        // BFS для поиска минимального количества пересадок
        int result = bfs(graph, N, A, B);
        System.out.println(result);
    }

    private static int bfs(List<List<Integer>> graph, int N, int start, int end) {
        boolean[] visited = new boolean[N + 1];
        Queue<Integer> queue = new LinkedList<>();
        Queue<Integer> transfers = new LinkedList<>();
        
        queue.add(start);
        transfers.add(0);
        visited[start] = true;

        while (!queue.isEmpty()) {
            int station = queue.poll();
            int transferCount = transfers.poll();

            for (int neighbor : graph.get(station)) {
                if (!visited[neighbor]) {
                    if (neighbor == end) {
                        return transferCount;
                    }
                    visited[neighbor] = true;
                    queue.add(neighbor);
                    transfers.add(transferCount + 1);
                }
            }
        }

        return -1;
    }
}
