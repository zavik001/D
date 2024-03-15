#include <iostream>
#include <bits/stdc++.h>


using namespace std;


int main()
{
   long long t;
   std::cin >> t;
   for (long long j = 0; j < t; j++)
   {
      string s;
      std::cin >> s;

      int n = s.size();

      bool SubString[n][n];

      // Initialize the SubString matrix
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
               SubString[i][j] = (s[i] == s[j] or s[i] == '?' or s[j] == '?');
         }
      }

      // Itterate over diagonal to find max tandem lenghth
      int max = 0;
      for (int i = 1; i < n; i++)
      {
         int count = 0;
         for (int row  = 0, col = i; row < n and col < n; row++, col++)
         {
               if (SubString[row][col])
               {
                  count++;
                  if (count >= i)
                  {
                     max = i;
                     break;
                  }
               }
               else
               {
                  // max = std::max(max, count);
                  count = 0;
               }
         }
         
      }
      std::cout << max*2 << std::endl;
   }
   return 0;
}
