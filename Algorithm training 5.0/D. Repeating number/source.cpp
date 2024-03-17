#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string hasRepeatedNumber(const vector<int>& A, int k) 
{
   unordered_map<int, int> lastIndex;

   for (int i = 0; i < A.size(); ++i) 
   {
      if (lastIndex.find(A[i]) != lastIndex.end() && i - lastIndex[A[i]] <= k) 
      {
         return "YES";
      }
      lastIndex[A[i]] = i;
   }

   return "NO";
}

int main() 
{
   int n, k;
   cin >> n >> k;

   vector<int> A(n);
   for (int i = 0; i < n; ++i) 
   {
      cin >> A[i];
   }

   cout << hasRepeatedNumber(A, k) << endl;

   return 0;
}
