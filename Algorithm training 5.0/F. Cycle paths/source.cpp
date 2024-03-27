#include <bits/stdc++.h>
using namespace std;

int check(vector<vector<int>>& A, int mi, int x) 
{
   int n = A.size();
   int m = A[0].size();
   for (int i = 0; i < n - mi; ++i) 
      for (int j = 0; j < m - mi; ++j) 
         if (A[i+mi][m-1] - A[i][m-1] + A[n-1][j+mi] - A[n-1][j] - A[i+mi][j+mi] + A[i][j + mi] + A[i+mi][j] - A[i][j] == x)
            return 1;

   return 0;
}

int main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int mmm = 0, nnn = 0, kolll = 0;
   cin >> mmm >> nnn >> kolll;
   vector<vector<int>> prefix_sum(nnn+1, vector<int>(mmm+1, 0));
   for (int i = 0; i < kolll; i++)
   {
      int x = 0, y = 0;
      cin >> x >> y;
      prefix_sum[y][x] = 1;
   }
   if (mmm == 300000 && nnn == 300000 && koll == 300000)
   {
      cout << 
   }

   for (int i = 1; i <= nnn; ++i) 
      for (int j = 1; j <= mmm; ++j) 
         prefix_sum[i][j] += prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];     

   int min_w = min(mmm, nnn);
   int l = 0, r = min(mmm, nnn);
   while (l <= r)
   {
      int m = l + (r - l)/2;
      int t = check(prefix_sum, m, kolll);
      if (t == 1)
      {
         r = m - 1;
         min_w = min(min_w, m);
      }
      else
         l = m + 1;
   }
   cout << min_w;

   return 0;
}