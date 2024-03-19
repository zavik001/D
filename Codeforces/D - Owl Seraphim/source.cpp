#include<bits/stdc++.h>
using namespace std;
int main()
{
   cin.tie(nullptr)->sync_with_stdio(false);
   long long t;
   cin >> t;
   for(long long i = 0;i < t;++i)
   {
      long long n,m;
      cin >> n >> m;
      long long a[n];
      long long b[n];
      for(long long j = 0;j < n;++j) cin >> a[j];
      for(long long j = 0;j < n;++j) cin >> b[j];
      long long ans = 1e18;
      long long sum = 0;
      for(long long j = n-1;j >= 0;--j)
      {
         if(j+1 <= m)
         {
            ans = min(ans,sum+a[j]);
         }
         sum =sum+min(a[j],b[j]);
      }
      cout << ans << endl;
              cout.flush(); // Сбрасываем буфер вывода

   }
}