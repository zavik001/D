#include <bits/stdc++.h>
using namespace std;

int f_mex(vector<int>& s, int n) 
{
   for(int mex = 0; mex < n; mex++) 
   {
      if(find(s.begin(), s.end(), mex) == s.end()) 
      {
         return mex;
      }
   }
   return n - 1;
}

void mex(vector<int>& s, int x, int n) 
{
   for (int i = 0; i < n; i++)
   {
      if (find(s.begin(), s.end(), i) == s.end())
      {
         s.push_back(i);
         if (f_mex(s, n) - i == x)return;
         else
         {
            s.pop_back();
         }
      }
   }
   return;
}

int main() {
   int t;
   cin >> t;
   while (t--) 
   {
      int n;
      cin >> n;
      vector<int> A(n), M;
      for (int i = 0; i < n; ++i) 
         cin >> A[i];

      if (A[0] == 1) M.push_back(0);
      else M.push_back(-A[0]);

      for (int i = 1; i < n; i++)
         mex(M, A[i], n);
      
      for (int i = 0 ; i < n; i++)
         cout << M[i] << " ";
      cout << "\n";
   }
   return 0;
}
