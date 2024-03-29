#include <bits/stdc++.h>
using namespace std;
int main ()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 0; cin >> t;
   while (t > 0)
   {
      int n = 0;
      cin >> n;
      for (int i = 1; i <= 2 * n; i ++) 
      {
        for (int j = 2; j <= 2 * n; j+=2) 
            if (j % 4 == 2) 
            {
               if (i % 4 == 1 || i % 4 == 2)
                  cout << "##";
               else  
                  cout << "..";
            }
            else 
            {
               if (i % 4 == 0 || i % 4 == 3)
                  cout << "##";
               else 
                  cout << "..";
            }
         std::cout << "\n";
      }
      t--;
   }

   return 0;
}