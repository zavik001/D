#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
const int mod = 998244353, N = 100005;

void solve() {
   int a, b, c;
   cin >> a >> b >> c;
   if (a + 1 != c) {
      cout << "-1\n";
      return;
   }
   priority_queue <int, vector <int>, greater <int>> pq;
   pq.push(0);
   for (int i = 0; i < a; ++i) {
      int d = pq.top(); pq.pop();
      pq.push(d + 1), pq.push(d + 1);
   }
   for (int i = 0; i < b; ++i) {
      int d = pq.top(); pq.pop();
      pq.push(d + 1);
   }
   int ans = 0;
   while (!pq.empty()) {
      int x = pq.top(); pq.pop();
      ans = max(ans, x);
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