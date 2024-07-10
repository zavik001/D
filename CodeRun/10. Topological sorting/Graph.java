import java.util.*;

class Graph {
    private int V;
    private List<Integer>[] adj;
    private int[] inDegree; 

    @SuppressWarnings("unchecked")
    public Graph(int V) {
        this.V = V;
        adj = (List<Integer>[]) new ArrayList[V];
        inDegree = new int[V];
        for (int i = 0; i < V; i++) {   
            adj[i] = new ArrayList<>();
            inDegree[i] = 0; 
        }
    }

    public void addEdge(int u, int v) {
        adj[u].add(v);
        inDegree[v]++; 
    }

    public List<Integer> topologicalSort() {
        List<Integer> result = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();

        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                queue.add(i);
            }
        }

        while (!queue.isEmpty()) {
            int v = queue.poll();
            result.add(v);

            for (int neighbor : adj[v]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    queue.add(neighbor);
                }
            }
        }

        if (result.size() != V) {
            return null; 
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt(), M = input.nextInt();
        Graph graph = new Graph(N);
        for (int i = 0; i < M; i++) {
            int v1 = input.nextInt() - 1, v2 = input.nextInt() - 1;
            graph.addEdge(v1, v2);
        }
        List<Integer> sortedVertices = graph.topologicalSort();
        if (sortedVertices == null) {
            System.out.println("-1");
        } else {
            for (int vertex : sortedVertices) {
                System.out.print((vertex + 1) + " ");
            }
        }
        input.close();
    }
}
