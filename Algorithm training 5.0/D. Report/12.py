def check(mid, w, arr):
   lines = 1
   width = mid
   for i in range(len(arr)):
      if width == mid:
         if arr[i] > width:
               return False
         width -= arr[i]
      elif width >= arr[i] + 1:
         width -= arr[i] + 1
      else:
         lines += 1
         width = mid - arr[i]
   return lines <= w

def solve():
   w, n, m = map(int, input().split())
   a = list(map(int, input().split()))
   b = list(map(int, input().split()))
   left = max(max(a), max(b))
   right = 10**9
   while right - left > 1:
      mid = (left + right) // 2
      if check(mid, w, a) and check(mid, w, b):
         right = mid
      else:
         left = mid
   print(right)

solve()
