#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>& PS, int k)
{
   int n = PS.size(), m = PS[0].size();
   for (int i = 0; i < n - 3 * k; i++)
   {
      for (int j = 0; j < m - 3 * k; j++)
      {
         int s1 = 0, s2 = 0, s = 0;
         s1 = PS[i + 2 * k][j + 3 * k] - PS[i + k][j + 3 * k] - PS[i + 2 * k][j] + PS[i + k][j];
         s2 = PS[i + 3 * k][j + 2 * k] - PS[i + 3 * k][j + k] - PS[i][j + 2 * k] + PS[i][j + k];
         s = PS[i + 2 * k][j + 2 * k] - PS[i + k][j + 2 * k] - PS[i + 2 * k][j + k] + PS[i + k][j + k];

         if (s1 + s2 - s == 5 * k * k)
            return true;
      }
   }
   return false;
}

int main ()
{
   int n = 0, m = 0;
   cin >> n >> m;

   vector<vector<int>> A(n, vector<int>(m, 0)), PS(n+1, vector<int>(m+1, 0));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         char c = '\0';
         cin >> c;
         if (c == '#')
            A[i][j] = 1;
      }
   }
   for (int i = 1; i <= n; ++i) 
      for (int j = 1; j <= m; ++j) 
         PS[i][j] = PS[i-1][j] + PS[i][j-1] - PS[i-1][j-1] + A[i - 1][j - 1];

   int l = 1, r = max(n, m);
   int max_k = r;
   while (l <= r)
   {
      int mid = l + (r - l)/2;
      if (check(PS, mid))
      {
         max_k = mid;
         l = mid + 1;
      }
      else
         r = mid - 1;
   }
   cout << max_k;

   return 0;
}
