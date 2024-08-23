import java.util.*;

public class ColoredPortals {
    static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        while (t-- > 0) {
            int n = scanner.nextInt();
            int q = scanner.nextInt();
            scanner.nextLine(); 
            
            String[] portals = scanner.nextLine().split(" ");
            
            Map<Character, List<Integer>> colorToCities = new HashMap<>();
            colorToCities.put('B', new ArrayList<>());
            colorToCities.put('G', new ArrayList<>());
            colorToCities.put('R', new ArrayList<>());
            colorToCities.put('Y', new ArrayList<>());
            
            for (int i = 0; i < n; i++) {
                char portal1 = portals[i].charAt(0);
                char portal2 = portals[i].charAt(1);
                colorToCities.get(portal1).add(i);
                colorToCities.get(portal2).add(i);
            }

            Map<Integer, List<Integer>> graph = new HashMap<>();
            for (int i = 0; i < n; i++) {
                graph.put(i, new ArrayList<>());
            }
            
            for (List<Integer> cities : colorToCities.values()) {
                for (int i = 0; i < cities.size(); i++) {
                    for (int j = i + 1; j < cities.size(); j++) {
                        int city1 = cities.get(i);
                        int city2 = cities.get(j);
                        graph.get(city1).add(city2);
                        graph.get(city2).add(city1);
                    }
                }
            }

            for (int i = 0; i < q; i++) {
                int x = scanner.nextInt() - 1;
                int y = scanner.nextInt() - 1;
                int result = dijkstra(graph, x, y, n);
                System.out.println(result);
            }
        }

        scanner.close();
    }

    public static int dijkstra(Map<Integer, List<Integer>> graph, int start, int end, int n) {
        if (start == end) return 0;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        pq.add(new int[]{start, 0});
        
        boolean[] visited = new boolean[n];
        int[] distances = new int[n];
        Arrays.fill(distances, INF);
        distances[start] = 0;

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int node = current[0];
            int distance = current[1];
            
            if (node == end) return distance;
            
            if (visited[node]) continue;
            visited[node] = true;
            
            for (int neighbor : graph.get(node)) {
                if (visited[neighbor]) continue;
                
                int newDist = distance + Math.abs(node - neighbor);
                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    pq.add(new int[]{neighbor, newDist});
                }
            }
        }
        return -1;  
    }
}
