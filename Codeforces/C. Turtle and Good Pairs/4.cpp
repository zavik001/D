#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    // Пара индексов
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);

    // Сортировка индексов по значениям a
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    // DP таблица
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MIN));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        int idx = indices[i];
        for (int j = m; j >= 1; --j) {
            for (int k = i - 1; k >= 0; --k) {
                int prevIdx = indices[k];
                if (b[prevIdx] != b[idx] && a[prevIdx] <= a[idx]) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[k + 1][j - 1] + c[idx]);
                }
            }
        }
    }

    long long result = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        result = max(result, dp[i + 1][m]);
    }

    if (result == LLONG_MIN) result = -1;
    
    cout << result << endl;

    return 0;
}
