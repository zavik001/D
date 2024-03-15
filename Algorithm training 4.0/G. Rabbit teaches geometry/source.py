N, M = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]

dp = [[0] * M for _ in range(N)]
max_square_size = 0

for i in range(N):
    for j in range(M):
        if grid[i][j] == 1:
            if i == 0 or j == 0:
                dp[i][j] = 1
            else:
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
            max_square_size = max(max_square_size, dp[i][j])

print(max_square_size)
