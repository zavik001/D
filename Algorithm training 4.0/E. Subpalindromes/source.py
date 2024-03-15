def Polindrome(s):
   n = len(s)
   ro, re = [0]*n, [0]*n
   l, r = 0, -1
   for i in range(n):
      k = 1 if i > r else min(ro[l + r - i], r - i + 1)
      while 0 <= i - k and i + k < n and s[i - k] == s[i + k]:
         k += 1
      ro[i] = k 
      k = k - 1
      if i + k > r:
         l, r = i - k, i + k

   l, r = 0, -1
   for i in range(n):
      k = 0 if i > r else min(re[l + r - i + 1], r - i + 1)
      while 0 <= i - k - 1 and i + k < n and s[i - k - 1] == s[i + k]:
         k += 1
      re[i] = k
      k = k - 1 
      if i + k > r:
         l, r = i - k - 1, i + k

   t = 0
   for i in range(n):
      t = t + ro[i]
   for i in range(n):
      t = t + re[i]        
      
   return t;

s = input()
print(Polindrome(s))