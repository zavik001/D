#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int n = 0, a = 0, b = 0, k = 0;

   cin >> n;
   vector<int> C(n + 1);

   for (int i = 0; i < n; i++)
      cin >> C[i];
   cin >> a >> b >> k;
   
   int x1 = (a - 1) / k ;
   int x2 = (b - 1) / k;
   int max = C[x1 % n];
   if (x2 - x1 >= n)
   {
      for (int i = 0; i < n; i++)
         if (max < C[i]) max = C[i];
      cout << max;
      return 0;
   }
   
   for (int i = x1; i <= x2; i++)
   {
      if (max < C[i % n]) max = C[i % n];
      if (max < C[(n - i % n) % n])max = C[(n - i % n) % n];
   }

   cout << max;

   return 0;
}