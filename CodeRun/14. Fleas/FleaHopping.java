import java.io.*;
import java.util.*;

public class FleaHopping {
    static final int[] dx = {-2, -1, 1, 2, 2, 1, -1, -2};
    static final int[] dy = {1, 2, 2, 1, -1, -2, -2, -1};
    static int N, M, S, T, Q;
    static int[][] dist;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken()) - 1; // converting to 0-based index
        T = Integer.parseInt(st.nextToken()) - 1; // converting to 0-based index
        Q = Integer.parseInt(st.nextToken());
        
        List<int[]> fleas = new ArrayList<>();
        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int fleaX = Integer.parseInt(st.nextToken()) - 1; // converting to 0-based index
            int fleaY = Integer.parseInt(st.nextToken()) - 1; // converting to 0-based index
            fleas.add(new int[]{fleaX, fleaY});
        }
        
        // Initialize distance array with -1 (unvisited)
        dist = new int[N][M];
        for (int[] row : dist) {
            Arrays.fill(row, -1);
        }
        
        // BFS to find shortest paths from the feeder (S, T)
        bfs(S, T);
        
        // Calculate the sum of minimum paths
        int totalDistance = 0;
        for (int[] flea : fleas) {
            int fleaX = flea[0];
            int fleaY = flea[1];
            if (dist[fleaX][fleaY] == -1) {
                System.out.println(-1);
                return;
            }
            totalDistance += dist[fleaX][fleaY];
        }
        
        System.out.println(totalDistance);
    }
    
    private static void bfs(int startX, int startY) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{startX, startY});
        dist[startX][startY] = 0;
        
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int x = current[0];
            int y = current[1];
            int currentDist = dist[x][y];
            
            for (int i = 0; i < 8; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if (isValid(newX, newY) && dist[newX][newY] == -1) {
                    dist[newX][newY] = currentDist + 1;
                    queue.offer(new int[]{newX, newY});
                }
            }
        }
    }
    
    private static boolean isValid(int x, int y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
}
