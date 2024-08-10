import java.util.*;

public class ArmyFormation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();
        
        @SuppressWarnings("unchecked")
        List<Integer>[] graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }
        
        int[] inDegree = new int[N + 1];
        
        for (int i = 0; i < M; i++) {
            int A = scanner.nextInt();
            int B = scanner.nextInt();
            graph[A].add(B);
            inDegree[B]++;
        }
        scanner.close();
        
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            if (inDegree[i] == 0) {
                queue.add(i);
            }
        }
        
        List<Integer> order = new ArrayList<>();
        while (!queue.isEmpty()) {
            int current = queue.poll();
            order.add(current);
            
            for (int neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    queue.add(neighbor);
                }
            }
        }
        
        if (order.size() == N) {
            System.out.println("Yes");
            for (int i = 0; i < order.size(); i++) {
                System.out.print(order.get(i));
                if (i < order.size() - 1) {
                    System.out.print(" ");
                }
            }
        } else {
            System.out.println("No");
        }
    }
}
