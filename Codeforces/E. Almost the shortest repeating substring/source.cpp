/**
 *    author:  tourist
 *    created: 28.03.2024 10:51:29
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int tt;
cin >> tt;
while (tt--) {
   int n;
   cin >> n;
   string s;
   cin >> s;
   for (int len = 1; len <= n; len++) {
   if (n % len == 0) {
      int sum = 0;
      for (int r = 0; r < len; r++) {
         vector<int> cnt(26, 0);
         int mx = 0;
         for (int i = r; i < n; i += len) {
         int c = int(s[i] - 'a');
         cnt[c] += 1;
         mx = max(mx, cnt[c]);
         }
         sum += mx;
      }
      if (sum >= n - 1) {
         cout << len << '\n';
         break;
      }
   }
   }
}
return 0;
}
