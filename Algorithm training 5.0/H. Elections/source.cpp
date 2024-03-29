#include <bits/stdc++.h>
using namespace std;

struct el
{
   long long v = 0;
   long long p = 0;
   long long n = 0;
   
   el(){} 
   el(long long _V, long long _p, long long _n) : v(_V), p(_p), n(_n) { }
};

int main ()
{
   long long n = 0;
   cin >> n;

   vector<el> A(n);
   vector<long long> P(n + 1);
   
   for (long long i = 0; i < n; i++)
   {
      long long v = 0, p = 0;
      cin >> v >> p;
      A[i] = {v, p, i+1};
   }
   sort(A.begin(), A.end(), [](const el& a, const el& b) { return a.v < b.v; });
   P[0] = 0;
   for (long long i = 1; i <= n; i++)
      P[i] = P[i - 1] + A[i - 1].v;

   long long max_A = LONG_LONG_MIN, kol_max_A = 0;
   for (long long i = 0; i < n; i++)
   {
      if (A[i].v > max_A)
      {
         kol_max_A = 0;
         max_A = A[i].v;
      }
      if (A[i].v == max_A)
         kol_max_A++;
   }

   vector<long long> B(max_A + 1);
   B[0] = 0;
   for (long long i = 0, j = 1; i < n; i++)
      for ( ; j <= A[i].v; j++)
         B[j] = B[j - 1] + (n - i);

   long long min_k = LONG_LONG_MAX, i_i = 0, k = 0;
   for (long long i = 0; i < n; i++)
   {
      cout << i << " " << A[i].n << " " << A[i].v << endl; 
      if (A[i].p == -1) continue;

      long long tec = A[i].v, dob = P[n] - P[i] - (n - i) * A[i].v;;
      tec += dob;

      if (tec == A[i].v)
      {
         tec++;
         if (i == n-1 && kol_max_A == 1)
            tec--;
      }
      if (tec > A[i].v + 2)
      {
         long long l = A[i].v + 1, r = A[n-1].v, maxx = 0;
         while (l <= r)
         {
            long long m = l + (r - l) / 2;
            if (tec - (B[m] - B[A[i].v]) > m)
            {
               maxx = m;
               l = m + 1;
            }
            else
               r = m - 1;
         }
         if (maxx > 0)
         {
            tec -= (B[maxx] - B[A[i].v]);
            if(tec > maxx + 1)
            {
               tec = maxx + 2;
            }
         }
         else 
         {
            tec = max_A + 1;
            if (kol_max_A == 1) tec--;
         }
      }
      
      if (tec - A[i].v + A[i].p < min_k)
      {
         k = tec - A[i].v;
         min_k = tec - A[i].v + A[i].p;
         i_i = i;
      }
   }
   cout << min_k << endl << A[i_i].n << endl;
   A[i_i].v += k;

   for (long long i = n - 1; i >= 0 && k > 0; i--)
   {
      if (i == i_i)continue;
      long long t = A[i].v - A[i_i].v;
      if (t >= 0)
      {
         A[i].v -= (t + 1);
         k -= (t+1);
      }
   }
   if (k > 0)
   {
      if (i_i != n-1)
         A[n-1].v -= k;
      else 
         A[n-2].v -= k;
   }

   sort(A.begin(), A.end(), [](const el& a, const el& b) { return a.n < b.n; });
   for (long long i = 0; i < n; i ++)
      cout << A[i].v << " ";

   return 0;
}