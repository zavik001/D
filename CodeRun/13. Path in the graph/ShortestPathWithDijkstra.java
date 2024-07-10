import java.util.*;

public class ShortestPathWithDijkstra {

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
        scanner.nextLine(); 

        List<List<Edge>> graph = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            graph.add(new ArrayList<>());
            for (int j = 0; j < N; j++) {
                int weight = scanner.nextInt();
                if (weight == 1) { 
                    graph.get(i).add(new Edge(j, 1)); 
                }
            }
            scanner.nextLine(); 
        }

        int start = scanner.nextInt() - 1;
        int end = scanner.nextInt() - 1;
        scanner.close();

        List<Integer> shortestPath = dijkstraWithPath(graph, N, start, end);
        if (shortestPath.isEmpty()) {
            System.out.println(-1);
        } else {
            System.out.println(shortestPath.size() - 1);
            for (int i = 0; i < shortestPath.size(); i++) {
                System.out.print(shortestPath.get(i) + 1);
                if (i < shortestPath.size() - 1) {
                    System.out.print(" ");
                }
            }
        }
    }

    private static List<Integer> dijkstraWithPath(List<List<Edge>> graph, int N, int start, int end) {
        int[] distance = new int[N];
        int[] parent = new int[N];
        Arrays.fill(distance, Integer.MAX_VALUE);
        Arrays.fill(parent, -1);
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
                    parent[v] = u;
                    pq.add(v);
                }
            }
        }

        List<Integer> path = new ArrayList<>();
        int current = end;
        while (current != -1) {
            path.add(current);
            current = parent[current];
        }

        Collections.reverse(path);
        if (path.get(0) != start) {
            path.clear(); 
        }

        return path;
    }
}
