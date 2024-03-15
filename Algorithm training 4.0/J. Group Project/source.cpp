#include <iostream>
#include <vector>

using namespace std;

int main() 
{
   long long t;
   cin >> t; 

   vector<vector<long long>> g(t, vector<long long>(3));

   
   for (int i = 0; i < t; i++) 
      for (int j = 0; j < 3; j++) 
         cin >> g[i][j]; 

   for (long long i = 0; i < t; i++) 
   {
      long long a = g[i][0] / g[i][1];
      if (g[i][0] % g[i][1] <= (g[i][2] - g[i][1]) * a)
         cout << "YES" << "\n";
      else
         cout << "NO" << "\n";
   }

   return 0;
}
