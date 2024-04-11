#include <iostream>
using namespace std;

int main() 
{
   int t;
   cin >> t;
   while (t--) 
   {
      int n, k;
      cin >> n >> k;
      if (k == n) {
         for (int i = 0; i < n; i++) 
         {
               cout << "1 ";
         }
         cout << "\n";
      } 
      else if (k > 1 && k < n) 
      {
         cout << "-1\n";
      } 
      else if (k == 1) 
      {
         for (int i = 1; i <= n; i++) 
         {
            cout << i << " ";
         }
         cout << "\n";
      } else 
      {
         cout << "-1\n";
      }
   }
   return 0;
}
