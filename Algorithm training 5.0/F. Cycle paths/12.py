def check(A, mi, x, m):
   n = len(A) // m
   for i in range(n - mi):
      for j in range(m - mi):
         if (A[(i + mi) * m + m - 1] - A[i * m + m - 1] + A[(n - 1) * m + j + mi] - A[(n - 1) * m + j] -
                  A[(i + mi) * m + j + mi] + A[i * m + j + mi] + A[(i + mi) * m + j] - A[i * m + j] == x):
               return True
   return False


mmm, nnn, kolll = map(int, input().split())
prefix_sum = [0] * ((nnn + 1) * (mmm + 1))
for _ in range(kolll):
   x, y = map(int, input().split())
   prefix_sum[y * (mmm + 1) + x] = 1

for i in range(1, nnn + 1):
   for j in range(1, mmm + 1):
      prefix_sum[i * (mmm + 1) + j] += (prefix_sum[(i - 1) * (mmm + 1) + j] +
                                          prefix_sum[i * (mmm + 1) + j - 1] -
                                          prefix_sum[(i - 1) * (mmm + 1) + j - 1])

min_w = min(mmm, nnn)
l, r = 0, min(mmm, nnn)
while l <= r:
   m = l + (r - l) // 2
   t = check(prefix_sum, m, kolll, mmm + 1)
   if t:
      r = m - 1
      min_w = min(min_w, m)
   else:
      l = m + 1

print(min_w)
