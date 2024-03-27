#include <iostream>
#include <vector>

using namespace std;

int bin(vector<long long> &S, long long k, long long s)
{
   long long l = 1, r = S.size() + 1 - k;
   while(l <= r)
   {
      long long m = l + (r - l)/2;
      long long x = S[m + k - 1] - S[m - 1];
      if (x == s)
         return m;
      else if (x < s)
         l = m + 1;
      else 
         r = m - 1;
   }
   return -1;
}

int main ()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   long long n = 0, m = 0;
   cin >> n >> m;
   
   vector<int> A(n); 
   vector<long long> Sum(n+1);
   Sum[0] = 0;
   for (int i = 0; i < n; i++)
   {
      cin >> A[i];
      Sum[i+1] = Sum[i] + A[i]; 
      //cout << Sum[i + 1] << "i" << endl; 
   }

   while(m--)
   {
      long long k = 0, s = 0;
      cin >> k >> s;

      cout <<  bin(Sum, k, s) << endl;
   }
   return 0;
}
