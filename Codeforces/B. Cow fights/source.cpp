#include <bits/stdc++.h>
using namespace std;

void solve()
{
   int n = 0, k = 0;
   cin >> n >> k;

   int max_ = 0;
   vector<int> A(n + 1);
   for(int i = 1; i <= n; i++)
      cin >> A[i];

   swap(A[1], A[k]);
   for(int i = 2; i <= n; i++)
      if (A[1] > A[i]) max_++;
      else break;

   int s = 0;
   swap(A[1], A[k]);
   for(int i = 1; i < k; i++)
      if(A[i] > A[k])
      {
         swap(A[i], A[k]);
         for(int j = i + 1; j <= n; j++)
         {
            if(A[j] > A[i])break;
            s++;
         }
         if(i > 1)s++;
         max_ = max(max_, s); 
         break;
      }
   
   cout << max_ << '\n';
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 0;
   cin >> t;

   while(t--)
      solve();

   return 0;
}