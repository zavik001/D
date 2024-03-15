#include <iostream>
#include <vector>

using namespace std;

int main() 
{
   unsigned long long k, n;
   cin >> k >> n;

   vector <int> floors(n+1);
   for (int i = 1; i <= n; i++) cin >> floors[i];
   
   unsigned long long time = 0;
   unsigned long long a = 0;
  
   for (int i = n; i > 0; i--)
   {
      if ((floors[i]<=0)) continue;

      a = 0;
      unsigned long long kol = floors[i] / k;
      time += kol * 2 * i;
      floors[i] -= kol * k;
      
      if (floors[i])
      {
         for (int j = i; j > 0; j--)
         {
            if (floors[j] + a >= k or j == 1)
            {
               time += i * 2;
               floors[j] -= k - a;
               break;
            }
            else
            {
               a += floors[j];
               floors[j] = 0;

            }
         }
      }
   }

   cout << time << endl;

   return 0;
}
