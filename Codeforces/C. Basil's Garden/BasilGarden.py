def solve(test_cases):
    for _ in range(test_cases):
        n = int(input())
        heights = list(map(int, input().split()))

        seconds = 0
        for i in range(n - 1, 0, -1):
            if heights[i] > heights[i - 1]:
                seconds += heights[i] - heights[i - 1]
            else:
                heights[i - 1] = heights[i]

            print(seconds)

if __name__ == "__main__":
    t = int(input())
    solve(t)
