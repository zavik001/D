#include <bits/stdc++.h>
using namespace std;
int main ()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 0; cin >> t;
   while (t > 0)
   {
      int a = 0, b = 0, c = 0;
      cin >> a >> b >> c;
      
      if (a < b && b < c)
         cout << "STAIR" << endl;
      else if (a < b && b > c)
         cout << "PEAK" << endl;
      else 
         cout << "NONE" << endl;

      t--;
   }

   return 0;
}