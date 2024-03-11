#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int t = 0;
   cin >> t;
   vector<bool>A(t, true);

   for (int i = 0; i < t; i++)
   {
      int n = 0;
      cin >> n;
      vector<int>B(n);

      for (int j = 0; j < n; j++)
         cin >> B[j];
      
      for (int j = 1; j < n - 1; j++)
      {
         int diff = B[j - 1] * 2;
         B[j] -= diff;
         B[j + 1] -= B[j-1];
         B[j-1] = 0;

         if (B[j] < 0 || B[j+1] < 0)
         {
            A[i] = false;
            break;
         }
      }

      if (A[i])
      {
         if (B[n-1] != 0)
            A[i] = false;
      }
   }

   for (int i = 0; i < t; i++)
      cout << (A[i] ? "YES" : "NO") << endl;

   return 0;
}