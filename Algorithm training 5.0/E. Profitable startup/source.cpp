#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

int main ()
{
   int n = 0, k = 0, d = 0;
   cin >> n >> k >> d;
   long long int Ans = 0;
   bool flag = false;
   
   Ans = n * 10;
   for (int i = 0; i < 10; i++)
   {
      if ((Ans + i) % k == 0)
      {
         Ans += i;
         flag = true;
         break;
      }
   }
      
   if (flag)
   {
      cout << Ans;
      for (int i = 1; i < d; i ++)
      {
         cout <<"0";  
      }
   }
   else 
   cout << -1;

   return 0;
}