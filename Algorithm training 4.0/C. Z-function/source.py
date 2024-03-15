def z_function(s):
   n = len(s)
   z = [0] * n
   l = r = 0
   for i in range(1, n):
      if i <= r:
         z[i] = min(r - i + 1, z[i - l])
      for j in range(z[i], n - i):
         if s[j] != s[i + j]:
               break
         z[i] += 1
      if i + z[i] - 1 > r:
         l, r = i, i + z[i] - 1
   return z

s = input()
z = z_function(s)

for i in range(len(z)):
   print(z[i], end=" ")
