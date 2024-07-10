import java.util.*;

public class CaveExplorer {
    static class Point {
        int x, y, z, dist;
        public Point(int x, int y, int z, int dist) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.dist = dist;
        }
    }

    static int N;
    static char[][][] cave;
    static boolean[][][] visited;

    static int[] dx = {0, 0, 0, 0, 1, -1};
    static int[] dy = {0, 0, 1, -1, 0, 0};
    static int[] dz = {1, -1, 0, 0, 0, 0};

    public static int bfs(int sx, int sy, int sz) {
        Queue<Point> queue = new LinkedList<>();
        queue.add(new Point(sx, sy, sz, 0));
        visited[sx][sy][sz] = true;

        while (!queue.isEmpty()) {
            Point p = queue.poll();

            if (p.z == 0 && cave[p.x][p.y][p.z] == '.') {
                return p.dist;
            }

            for (int i = 0; i < 6; i++) {
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];
                int nz = p.z + dz[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N && nz >= 0 && nz < N &&
                    cave[nx][ny][nz] == '.' && !visited[nx][ny][nz]) {
                    visited[nx][ny][nz] = true;
                    queue.add(new Point(nx, ny, nz, p.dist + 1));
                }
            }
        }

        return -1; // Should never reach here as the exit is always possible
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        cave = new char[N][N][N];
        visited = new boolean[N][N][N];

        int startX = -1, startY = -1, startZ = -1;

        for (int z = 0; z < N; z++) {
            scanner.nextLine(); // skip the empty line
            for (int x = 0; x < N; x++) {
                String line = scanner.nextLine();
                for (int y = 0; y < N; y++) {
                    cave[x][y][z] = line.charAt(y);
                    if (cave[x][y][z] == 'S') {
                        startX = x;
                        startY = y;
                        startZ = z;
                        cave[x][y][z] = '.'; // treat the start position as free space
                    }
                }
            }
        }

        int result = bfs(startX, startY, startZ);
        System.out.println(result);
    }
}
