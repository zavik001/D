#include<bits/stdc++.h>
using namespace std;

void interval(vector<int> &A, string &s)
{
   size_t n = A.size();

   sort(A.begin(), A.end());

   for (int i = 0; i < n; )
   {
      int start = i;
      int end = i;

      for ( ; end + 1 < n && A[end] + 1 == A[end+1]; end++);
      i = end + 1;

      if (start == end)
         s += to_string(A[start]);
      else
         s += to_string(A[start]) + "-" + to_string(A[end]);

      if (i <= n - 1)
         s += ","; 
   }

   return;
}

int main()
{
   int n = 0;
   cin >> n;

   vector<int> A(n);
   for (int i = 0; i < n; i++)
      cin >> A[i];

   string s;
   s.resize(2*n + 1);

   interval(A, s);

   cout << s;

   return 0;
}