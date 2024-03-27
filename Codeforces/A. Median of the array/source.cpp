#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int t = 0; cin >> t;
   for ( ; t > 0; t--)
   {
      int n = 0;
      cin >> n;
      vector<int> A(n);

      for (int i = 0; i < n; i++)
         cin >> A[i];

      sort(A.begin(), A.end());

      int mid = n % 2 == 0 ? n / 2 : n / 2 + 1; mid--;
      int kol = 1;

      for (int i = mid + 1; i < n && A[mid] == A[i]; kol++, i++);

      if (n == 1)
         cout << 1 << "\n";
      else
         cout << kol << "\n";
   }
}