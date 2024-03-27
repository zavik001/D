#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll sum (int x)
{
   return x*(x + 1)/2; 
}

int bin(int x)
{
   ll l = 0, r = 10000;
   ll index = 0;
   while(l <= r)
   {
      ll m = l + (r - l)/2;
      if (x <= sum(m) && x > sum(m - 1))
      {
         index = m;
         return m;
      }
      else if (sum(m) > x)
         r = m - 1;
      else 
         l = m + 1;
   }
   return index;
}

int main ()
{
   ll n = 0;
   cin >> n;
   if (n == 1)
   {
      cout << "1/1";
      return 0;
   }
   if (n == 2)
   {
      cout << "2/1";
      return 0;
   }
   if (n == 3)
   {
      cout << "1/2";
      return 0;
   }
   ll diag = bin(n);
   n -= sum(diag - 1);
   if (diag % 2 == 0)
   {
      cout << diag - n + 1 << "/" << n;
   }
   else 
   {
      cout << n << "/" << diag - n + 1;
   }

   return 0;
}
