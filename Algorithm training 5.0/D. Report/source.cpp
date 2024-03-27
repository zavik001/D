#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll w = 0, n = 0, mm = 0;

ll kol(vector<ll>& A,ll l, ll m)
{
   ll n = A.size() - 1;
   ll kur = 0;
   ll kol = 1;
   if (A[0] + l > m)
      return n+m;

   kur = A[0] + l;

   for (ll i = 1; i <= n; i++)
   {
      if (A[i] + l > m )
         return n+m;
      
      if (kur + 1 + A[i] <= m)
      {
         kur += A[i] + 1;
      }
      else
      {
         kol++;
         kur = A[i] + l;
      }
   }
   return kol;
}

int main ()
{
   cin >> w >> n >> mm;
   vector<ll> A(n), B(mm);

   for (ll i = 0; i < n; i++)
      cin >> A[i];

   for (ll i = 0; i < mm; i++)
      cin >> B[i];

   ll mi = n + mm;
   ll l = 0, r = w;
   while(l <= r)
   {
      ll m = l + (r - l)/2;
      if (r == 1 && l == 0)
         m = 1;
      if (m == 0)
         break;
      
      cout << endl << m;
      ll kol1 = kol(A, 0, m);
      ll kol2 = kol(B, m, w);
      cout << " " << kol1 << " " << kol2;

      if (kol1 == kol2)
      {
         mi = min(mi, kol1);
         break;
      }
      else if ((kol1 < kol2 || kol2 == n+m))
      {
         r = m - 1;
         mi = min(mi, kol2);
      }
      else
      {
         l = m + 1;
         mi = min(mi, kol1);
      }
   }
   cout << endl << mi;

   return 0;
}
