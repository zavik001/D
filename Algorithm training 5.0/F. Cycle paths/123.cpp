#include <bits/stdc++.h>
using namespace std;

bool check(vector<pair<int, int>>& A, vector<pair<int, int>>& B, vector<pair<int, int>>& C, int w)
{
   int n = A.size();
   for (int i = 0, j = 0; i < n; i++)
   {
      for ( ; j < n && A[j].first - A[i].first < w; j++);
      if (j > i) j--;
      int min_val = min(B[i].first, C[j].first);
      int max_val = max(B[i].second, C[j].second);
      if (max_val - min_val < w)
         return true;
   }

   return false;
}

int main ()
{
   int w = 0, h = 0, n = 0;
   cin >> w >> h >> n;
   
   vector<pair<int, int>> A(n), B(n), C(n);
   for (int i = 0; i < n; i++)
      cin >> A[i].second >> A[i].first;
   sort(A.begin(), A.end());

   int min_ = A[0].second, max_ = A[0].second;
   B[0] = {INT_MAX, INT_MIN};
   for (int i = 1; i < n; i++)
   {
      if (A[i - 1].second < min_)
         min_ = A[i - 1].second;

      if (A[i - 1].second > max_)
         max_ = A[i - 1].second;

      B[i] = {min_, max_};
   }

   min_ = A[n - 1].second; max_ = A[n - 1].second;
   C[n - 1] = {INT_MAX, INT_MIN};
   for (int i = n - 2; i >= 0; i--)
   {
      if (A[i + 1].second < min_)
         min_ = A[i + 1].second;

      if (A[i + 1].second > max_)
         max_ = A[i + 1].second;

      C[i] = {min_, max_};
   }

   int l = 0, r = min(w, h);
   int min_w = r;
   while (r - l > 0)
   {
      int mid = (r + l) / 2;
      if (check(A, B, C, mid))
      {
         min_w = mid;
         r = mid;
      }
      else 
         l = mid + 1;
   }
   cout << min_w;

   return 0;
}