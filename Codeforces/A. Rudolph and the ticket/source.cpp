#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
   int t = 0;
   cin >> t;

   vector<int> A(t);

   for (int j = 0; j < t; j ++)
   {
      int n = 0, m = 0, k = 0;
      cin >> n >> m >> k;
      vector<int> B(n), C(m);

      for (int i = 0; i < n; i++)
         cin >> B[i];
      for (int i = 0; i < m; i++)
         cin >> C[i];
      
      sort(B.begin(), B.end());
      sort(C.begin(), C.end());

      for(int i = 0; B[i] < k && i < n; i++)
         for (int l = 0; C[l] + B[i] <= k && l < m; l++, A[j]++);
   }

   for (int i = 0; i < t; i++)
      cout << A[i] << endl;
   
   if (t == 0)
      cout << 0;
   return 0;   
}