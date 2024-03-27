def sum(x):
   return x * (x + 1) // 2

def bin_search(x):
   l, r = 1, 10000000
   index = 1
   while l <= r:
      m = l + (r - l) // 2
      if x <= sum(m) and x > sum(m - 1):
         index = m
         return m
      elif sum(m) > x:
         r = m - 1
      else:
         l = m + 1
   return index

if __name__ == "__main__":
   n = int(input())
   diag = bin_search(n)
   n -= sum(diag - 1)
   if diag % 2 == 0:
      print(diag - n + 1, "/", n, sep="")
   else:
      print(n, "/", diag - n + 1, sep="")
