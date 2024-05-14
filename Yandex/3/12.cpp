#include <bits/stdc++.h>
using namespace std;

int main ()
{
   int n = 0;
   cin >> n;
   
   vector<pair<int, int>> A(n);

   for (int i = 0; i < n; i++)
      cin >> A[i].first >> A[i].second;

   sort(A.begin(), A.end());
   vector<int> maxPrefix(n), minSuffix(n);

   int maxVal = A[0].second, minVal = A[n - 1].second;
   maxPrefix[0] = INT_MIN;
   minSuffix[n - 1] = INT_MAX; 

   for (int i = 1; i < n; i++) 
   {
      if (A[i - 1].second > maxVal) 
         maxVal = A[i - 1].second; 
      maxPrefix[i] = maxVal;

      if (A[n - i].second < minVal)
         minVal = A[n - i].second;
      minSuffix[n - i - 1] = minVal;
   }

   int count = 0;
   for (int i = 0; i < n; i++)
   {
      int maxP = maxPrefix[i], minS =  minSuffix[i];
      if (A[i].second > maxP && A[i].second < minS)
         count ++;
   }

   cout << count;

   return 0;
}