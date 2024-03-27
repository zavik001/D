def sum(k):
   sum_val = k * k + 6 * k + 5
   return sum_val * k // 6 - 1

def main():
   n = int(input())
   if n == 0:
      print(0)
      return

   l, r = 1, 2500000
   while l <= r:
      m = l + (r - l) // 2
      if sum(m) <= n and sum(m + 1) > n:
         print(m)
         return
      elif sum(m) < n:
         l = m + 1
      else:
         r = m - 1

if __name__ == "__main__":
   main()
