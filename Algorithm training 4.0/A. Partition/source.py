def partition(arr, x):
   i = 0
   for j in range(len(arr)):
      if arr[j] < x:
         arr[i], arr[j] = arr[j], arr[i]
         i += 1
   return i

N = int(input())
arr = list(map(int, input().split()))
x = int(input())
pivot = partition(arr, x)
print(pivot)
print(N - pivot)
