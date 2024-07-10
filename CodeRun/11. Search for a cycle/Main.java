import java.util.*;

public class Main {

    static int n;
    static int[][] graph;
    static boolean[] visited;
    static int[] parent;
    static List<Integer> cycle;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        graph = new int[n][n];
        visited = new boolean[n];
        parent = new int[n];
        cycle = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = scanner.nextInt();
            }
        }

        if (findCycle()) {
            System.out.println("YES");
            System.out.println(cycle.size() - 1);
            for (int i = cycle.size() - 2; i >= 0; i--) {
                System.out.print((cycle.get(i) + 1) + " ");
            }
        } else {
            System.out.println("NO");
        }
    }

    static boolean findCycle() {
        Arrays.fill(visited, false);
        Arrays.fill(parent, -1);
        cycle.clear();

        for (int v = 0; v < n; v++) {
            if (!visited[v] && dfs(v, -1)) {
                return true;
            }
        }
        return false;
    }

    static boolean dfs(int v, int p) {
        visited[v] = true;
        parent[v] = p;

        for (int u = 0; u < n; u++) {
            if (graph[v][u] == 1) {
                if (!visited[u]) {
                    if (dfs(u, v)) {
                        return true;
                    }
                } else if (u != p) {
                    // Found a cycle
                    int current = v;
                    cycle.add(current);
                    while (current != u) {
                        current = parent[current];
                        cycle.add(current);
                    }
                    cycle.add(u);
                    return true;
                }
            }
        }
        return false;
    }
}
