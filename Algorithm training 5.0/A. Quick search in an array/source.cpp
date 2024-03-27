#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binl(const vector<int>& A, int left) 
{
   int n = A.size();
   int leftmost = -1;

   int l = 0, r = n - 1;
   while (l <= r) 
   {
      int m = l + (r - l) / 2;
      if (A[m] == left || (m > 0 && left > A[m - 1] && left < A[m])) 
      {
         leftmost = m;
         r = m - 1;
      } 
      else if (A[m] < left) 
         l = m + 1;
      else 
         r = m - 1;
   }

   if (left < A[0])
      return 0;
   return leftmost;
}

int binr(const vector<int>& A, int right) 
{
   int n = A.size();
   int rightmost = -1;

   int l = 0, r = n - 1;
   while (l <= r) 
   {
      int m = l + (r - l) / 2;
      if (A[m] == right || (m < n - 1 && right > A[m] && right < A[m + 1])) 
      {
         rightmost = m;
         l = m + 1;
      } 
      else if (A[m] < right) 
         l = m + 1;
      else 
         r = m - 1;
   }

   if (right > A[n-1])
      return n - 1;
   return rightmost;
}

int main() 
{
   int n, k;
   cin >> n;
   vector<int> A(n);
   for (int i = 0; i < n; i++) 
      cin >> A[i];
   sort(A.begin(), A.end());
   cout << endl;
   for (int i = 0; i < n; i++)
      cout << A[i] << " ";
   cout << endl;

   cin >> k;
   vector<pair<int, int>> B(k);
   for (int i = 0; i < k; i++) 
      cin >> B[i].first >> B[i].second;

   for (int i = 0; i < k; i++) 
   {
      int kol = 0;
      int l = binl(A, B[i].first);
      int r = binr(A, B[i].second);
      if (l != -1 && r != -1) 
         kol += r - l + 1;

      cout << kol << " ";
   }

   return 0;
}
