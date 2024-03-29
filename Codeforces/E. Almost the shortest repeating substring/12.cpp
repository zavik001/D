#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
const int mod = 998244353, N = 100005;

void solve() {
   int n;
   string s;
   cin >> n >> s;
   int ans = n;
   auto check = [&](int k) {
      int cnt = 0;
      for (int i = 0; i < k; ++i) {
         vector <int> res(26);
         int mx = 0;
         for (int j = i; j < n; j += k) {
               res[s[j] - 'a']++;
               mx = max(mx, res[s[j] - 'a']);
         }
         cnt += mx;
      }
      if (cnt + 1 >= n) {
         ans = min(ans, k);
      }
   };
   for (int i = 1; i * i <= n; ++i) if (n % i == 0) {
      check(i), check(n / i);
   }
   cout << ans << '\n';
}

int main() {
   ios::sync_with_stdio(false), cin.tie(0);
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
}