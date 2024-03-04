import math

n, k, d = map(int, input().split())
ans = 0
flag = False

ans = n * 10
for i in range(10):
    if (ans + i) % k == 0:
        ans += i
        flag = True
        break

ans = ans * pow(10, d-1)
print(ans if flag else -1)
