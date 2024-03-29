def count_deletions(n, songs):
   dp = [float('inf')] * (1 << n)
   dp[0] = 0
   
   for mask in range(1, 1 << n):
      for j in range(n):
         if (mask >> j) & 1:
               prev_mask = mask ^ (1 << j)
               prev_song = songs[j]
               for k in range(n):
                  if (prev_mask >> k) & 1:
                     if prev_song[0] == songs[k][0] or prev_song[1] == songs[k][1]:
                           dp[mask] = min(dp[mask], dp[prev_mask])
   
   return dp[(1 << n) - 1]

t = int(input())
for _ in range(t):
   n = int(input())
   songs = [input().split() for _ in range(n)]
   print(count_deletions(n, songs))
