#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
	int n; cin >> n;
	vector<string> g(2);
	cin >> g[0];
	cin >> g[1];
	vector<vector<bool>> vis(2, vector<bool>(n, false));
	auto dfs = [&](auto self, int x, int y, bool pow) -> void {
		if (x < 0 || x > 1 || y >= n || y < 0 || vis[x][y]) {
			return;
		}
		vis[x][y] = true;
		if (!pow) {
			self(self, x, y + (g[x][y] == '>' ? 1 : -1), true);
		} else {
			self(self, x, y + 1, false);
			self(self, !x, y, false);
		}
	};
	dfs(dfs, 0, 0, true);
	cout << (vis[1][n - 1] ? "YES" : "NO") << '\n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
