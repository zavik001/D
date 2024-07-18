import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static class Node {
        int id;
        long attack;

        Node(int id, long attack) {
            this.id = id;
            this.attack = attack;
        }
    }

    static List<List<Integer>> graph;
    static long totalHealthReduction;

    static void dfs(int u, int parent, List<Node> monsters) {
        long attackSum = 0;
        for (int v : graph.get(u)) {
            if (v != parent) {
                dfs(v, u, monsters);
                attackSum += monsters.get(v).attack;
            }
        }
        totalHealthReduction += Math.min(attackSum, monsters.get(u).attack);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            List<Node> monsters = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                long attack = scanner.nextLong();
                monsters.add(new Node(i, attack));
            }

            graph = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                graph.add(new ArrayList<>());
            }

            for (int i = 0; i < n - 1; i++) {
                int x = scanner.nextInt() - 1;
                int y = scanner.nextInt() - 1;
                graph.get(x).add(y);
                graph.get(y).add(x);
            }
            totalHealthReduction = 0;
            dfs(0, -1, monsters);
            System.out.println(totalHealthReduction);
        }
    }
}
