def min_length(s):
   n = len(s)
   prefix_func = [0]*n
   for i in range(1,n):
      j = prefix_func[i-1]
      while j > 0 and s[i] != s[j]:
         j = prefix_func[j-1]
      if s[i] == s[j]:
         j += 1
      prefix_func[i] = j
   return n - prefix_func[-1]

s = input()
print(min_length(s))
