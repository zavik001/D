def print_array(arr):
   print(', '.join(arr))

def print_buckets(buckets):
   for i in range(len(buckets)):
      print(f'Bucket {i}: ', end='')
      if not buckets[i]:
         print('empty')
      else:
         print(', '.join(buckets[i]))

def radix_sort(arr):
   max_len = len(arr[0])

   for i in range(max_len):
      buckets = [[] for _ in range(10)]

      for s in arr:
         digit = int(s[max_len - 1 - i])
         buckets[digit].append(s)

      print('**********')
      print(f'Phase {i + 1}')
      print_buckets(buckets)

      arr.clear()
      for bucket in buckets:
         for s in bucket:
               arr.append(s)

N = int(input())
arr = [input() for _ in range(N)]

print('Initial array:')
print_array(arr)

radix_sort(arr)

print('**********')
print('Sorted array:')
print_array(arr)
