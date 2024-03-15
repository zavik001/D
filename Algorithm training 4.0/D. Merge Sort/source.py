def merge(arr, l, r):
   i = j = k = 0
   while i < len(l) and j < len(r):
      if (l[i] <= r[j]):
         arr[k] = l[i]
         i += 1
      else:
         arr[k] = r[j]
         j += 1
      k += 1

   while i < len(l):
      arr[k] = l[i]
      i += 1
      k += 1

   while j < len(r):
      arr[k] = r[j]
      j += 1
      k += 1

def merge_sort(arr):
   if len(arr) > 1:
      mid = len(arr) // 2
      l = arr[:mid]
      r = arr[mid:]

      merge_sort(l)
      merge_sort(r)

      merge(arr, l, r)

n = int(input())
arr = list(map(int, input().split()))
merge_sort(arr)
for i in arr:
   print(i, end=" ")
