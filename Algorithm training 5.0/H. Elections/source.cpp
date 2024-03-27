#include <bits/stdc++.h>
using namespace std;

struct el
{
   long long v = 0;
   int p = 0;
   int n = 0;
   
   el(){} 
   el(long long _V, int _p, int _n) : v(_V), p(_p), n(_n) { }
};

int main ()
{
   int n = 0;
   cin >> n;

   vector<el> A(n);
   vector<long long> P(n + 1);
   for (int i = 0; i < n; i++)
   {
      int v = 0, p = 0;
      cin >> v >> p;
      A[i] = {v, p, i+1};
   }
   sort(A.begin(), A.end(), [](const el& a, const el& b) { return a.v < b.v; });

   P[0] = 0;
   for (int i = 1; i <= n; i++)
      P[i] = P[i - 1] + A[i - 1].v;


   int max_A = INT_MIN, kol_max_A = 0;
   for (int i = 0; i < n; i++)
   {
      if (A[i].v > max_A)
      {
         kol_max_A = 0;
         max_A = A[i].v;
      }
      if (A[i].v == max_A)
         kol_max_A++;
   }

   long long min_k = INT_MAX;
   int i_i = 0, kolll = 0;
   for (int i = 0; i < n; i++)
   {
      int l = i, r = n - 1;
      long long kol = INT_MAX;
      //cout << "для :" << A[i].n << " " << A[i].v << " " << A[i].p<< " V добовить: ";  
      while (l <= r && A[i].p >= 0)
      {
         int mid = l + (r - l)/2;
         long long tec = A[i].v;
         long long dob = P[n] - P[mid] - (n - mid) * A[mid].v;
         tec += dob;
         if (tec >= A[mid].v)
         {
            if (tec == A[mid].v)
            {
               tec++;
               if (i == n-1 && kol_max_A == 1)
                  tec--;
            }
            if (tec > A[mid].v + 2)
            {
               bool flag = true;
               if (kol_max_A > 2)
               {

               }
               int x = n - mid - 1;
               int ll = A[mid].v, rr = A[mid + 1].v - 2;
               long long maxx = INT_MIN;
               while (ll <= rr)
               {
                  int midd = ll + (rr - ll)/2;
                  if (tec - (midd - A[mid].v) * x > midd)
                  {
                     maxx = max(maxx, midd - A[mid].v);
                     ll = midd + 1;
                  }
                  else 
                     rr = midd - 1;
               }
               if (flag)
                  tec -= maxx * (x);
            }
            kol = min(kol, tec);
         
            l = mid + 1;
         }
         else  
            r = mid - 1;
      }
      //cout << kol - A[i].v << endl;
      if (A[i].p >= 0 && kol - A[i].v + A[i].p < min_k)
      {
         kolll = kol - A[i].v;
         min_k = kol - A[i].v + A[i].p;
         i_i = i;
      }
   }
   cout << min_k << endl << A[i_i].n << endl;
   A[i_i].v += kolll;

   for (int i = n - 1; i >= 0 && kolll > 0; i--)
   {
      if (i == i_i)continue;
      int t = A[i].v - A[i_i].v;
      if (t >= 0)
      {
         A[i].v -= (t + 1);
         kolll -= (t+1);
      }
   }
   if (kolll > 0)
   {
      if (i_i != n-1)
         A[n-1].v -= kolll;
      else 
         A[n-2].v -= kolll;
   }

   sort(A.begin(), A.end(), [](const el& a, const el& b) { return a.n < b.n; });
   for (int i = 0; i < n; i ++)
      cout << A[i].v << " ";

   return 0;
}