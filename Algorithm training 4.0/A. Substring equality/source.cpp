#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll P = 31;
const ll MOD = 1e9 + 7;

int main() 
{
   string S;
   cin >> S;

   int Q;
   cin >> Q;
   vector<vector<int>> Arr(Q, vector<int>(3));
   for (int i = 0; i < Q; i++)
      cin >> Arr[i][0] >> Arr[i][1] >> Arr[i][2];

   vector<ll> p_pow(S.size() + 1), h(S.size() + 1);
   p_pow[1] = 1;
   h[1] = S[0] - 'a' + 1;
   for (int i = 2; i <= S.size(); i++) 
   {
      p_pow[i] = (p_pow[i - 1] * P) % MOD;
      h[i] = (h[i - 1] * P + S[i - 1] - 'a' + 1) % MOD;
   }

   for (int i = 0; i < Q; i++)
   {
      int L = Arr[i][0], A = Arr[i][1], B = Arr[i][2];
      ll c = (h[A + L] + h[B] * p_pow[L + 1]) % MOD;
      ll d = (h[B + L] + h[A] * p_pow[L + 1]) % MOD;
      if (c == d)
         cout << "yes\n";
      else
         cout << "no\n";
   }

   return 0;
}
