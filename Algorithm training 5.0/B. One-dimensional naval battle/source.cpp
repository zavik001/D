#include <iostream>
using namespace std;

int128_t sum(int k) 
{
   int128_t sum = k*k + 6*k + 5;
   return sum * k / 6 - 1;
}

int main()
{
   int128_t n = 0;
   cin >> n;
   if (n == 0)
   {
      cout << 0;
      return 0;
   }

   int128_t l = 1, r = 1000000;
   while(l <= r)
   {
      int128_t m = l + (r - l)/2;
      if (sum(m) <= n && sum(m + 1) > n)
      {
         cout << m;
         return 0;
      }
      else if (sum(m) < n)
      {
         l = m + 1;
      }
      else 
      {
         r = m - 1;
      }
   }
   
   return 0;
}