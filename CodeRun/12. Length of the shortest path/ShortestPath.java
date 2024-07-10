import java.util.*;

public class ShortestPath {

    static class Edge {
        int to;
        int weight;

        public Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        scanner.nextLine(); // consume newline character

        List<List<Edge>> graph = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
            for (int j = 0; j < N; j++) {
                int weight = scanner.nextInt();
                if (weight == 1) { // there is an edge
                    graph.get(i).add(new Edge(j, 1)); // assuming all edges have weight 1
                }
            }
            scanner.nextLine(); // consume newline character
        }

        int start = scanner.nextInt() - 1;
        int end = scanner.nextInt() - 1;
        scanner.close();

        int shortestPathLength = dijkstra(graph, N, start, end);
        System.out.println(shortestPathLength);
    }

    private static int dijkstra(List<List<Edge>> graph, int N, int start, int end) {
        int[] distance = new int[N];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[start] = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.comparingInt(v -> distance[v]));
        pq.add(start);

        while (!pq.isEmpty()) {
            int u = pq.poll();

            for (Edge edge : graph.get(u)) {
                int v = edge.to;
                int weight = edge.weight;

                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.add(v);
                }
            }
        }

        return distance[end] == Integer.MAX_VALUE ? -1 : distance[end];
    }
}
