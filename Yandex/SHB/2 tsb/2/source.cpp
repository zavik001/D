#include<bits/stdc++.h>
using namespace std;

int main() 
{
   int n, k;
   cin >> n >> k;
   vector<int> A(n), S(n);

   long long s = 0;
   priority_queue<pair<int, int>> Q; 
   for (int i = 0; i < n; i++) 
   {
      cin >> A[i];
      Q.push({-A[i], i}); 

      for( ; Q.top().second < i - k + 1; Q.pop());

      S[Q.top().second]++;
      s -= Q.top().first;
   }

   cout << s << endl;
   for (int i = 0; i < n; i++) 
      cout << S[i] << " ";

   return 0;
}