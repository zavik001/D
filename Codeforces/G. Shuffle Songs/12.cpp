#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
const int mod = 998244353, N = 100005;
 
void solve() {
    int n;
    cin >> n;
    map <string, int> m1;
    int _id = 0;
    auto get = [&](string s) {
        if (m1.count(s)) {
            return m1[s];
        }
        return m1[s] = _id++;
    };
    vector <pii> a(n);
    for (int i = 0; i < n; ++i) {
        string s, t; cin >> s >> t;
        a[i].first = get(s), a[i].second = get(t);
    }
    auto check = [&](int i, int j) {
        return a[i].first == a[j].first || a[i].second == a[j].second;
    };
    vector dp(n, vector <bool>(1 << n, 0));
    for (int i = 0; i < n; ++i) {
        dp[i][1 << i] = true;
    }
    for (int msk = 1; msk < 1 << n; ++msk) {
        for (int i = 0; i < n; ++i) if (msk >> i & 1 && dp[i][msk]) {
            for (int k = 0; k < n; ++k) if (~msk >> k & 1 && check(i, k)) {
                dp[k][msk | (1 << k)] = true;
            }
        }
    }
    int ans = 1 << 30;
    for (int i = 0; i < 1 << n; ++i) {
        for (int k = 0; k < n; ++k) if (dp[k][i]) {
            ans = min(ans, n - __builtin_popcount(i));
        }
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