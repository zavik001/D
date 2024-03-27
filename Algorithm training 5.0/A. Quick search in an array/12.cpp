#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main ()
{
   int n = 0, k = 0;
   cin >>  n;
   vector <int> A(n);
   for (int i = 0; i < n; i++)
      cin >> A[i];

   cin >> k;
   vector<pair<int, int>> B(k);
   for (int i = 0; i < k; i++)
      cin >> B[i].first >> B[i].second;
   
   for (int i = 0; i < k; i++)
   {
      int kol = 0;
      for (int j = 0; j < n; j++)
      {
         if (A[j] >= B[i].first && A[j] <= B[i].second)
            kol++;
      }
      
      cout << kol << " ";
   }
   
   return 0;
}
