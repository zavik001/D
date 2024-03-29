/**
 *    author:  tourist
 *    created: 28.03.2024 10:56:29
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
    vector<string> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    vector<vector<bool>> edge(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        edge[i][j] = (a[i] == a[j] || b[i] == b[j]);
      }
    }
    vector<vector<bool>> dp(1 << n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
      dp[1 << i][i] = true;
    }
    int ans = 0;
    for (int t = 1; t < (1 << n); t++) {
      for (int i = 0; i < n; i++) {
        if (dp[t][i]) {
          ans = max(ans, __builtin_popcount(t));
          for (int j = 0; j < n; j++) {
            if (!(t & (1 << j))) {
              if (edge[i][j] || edge[j][i]) {
                dp[t | (1 << j)][j] = true;
              }
            }
          }
        }
      }
    }
    cout << n - ans << '\n';
  }
  return 0;
}
