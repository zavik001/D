#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> cost(N);
    for (int i = 0; i < N; ++i) {
        cin >> cost[i];
    }

    vector<int> dp(N, 0);
    vector<int> coupons(N, 0);

    for (int i = 1; i < N; ++i) {
        dp[i] = dp[i - 1] + cost[i];
        coupons[i] = coupons[i - 1];

        if (dp[i] >= 100) {
            dp[i] = dp[i - 1];
            coupons[i]++;
        }
    }

    int minCost = dp[N - 1];
    int usedCoupons = coupons[N - 1];

    cout << minCost << endl;
    cout << usedCoupons << " " << N - usedCoupons << endl;

    for (int i = 0; i < N; ++i) {
        if (coupons[i] == 1) {
            cout << i + 1 << endl;
        }
    }

    return 0;
}
