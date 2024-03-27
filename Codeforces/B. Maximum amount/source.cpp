#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Calculate prefix sum of array 'a'
        vector<int> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix_sum[i + 1] = (prefix_sum[i] + a[i]) % MOD;
        }

        // Initialize 'max_sum' with negative infinity
        int max_sum = INT_MIN;

        // Iterate over all possible subarrays
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                // Calculate the sum of subarray a[i:j+1]
                int subarray_sum = (prefix_sum[j + 1] - prefix_sum[i] + MOD) % MOD;

                // Calculate the contribution of this subarray after k operations
                int contribution = (1LL * subarray_sum * (1LL << k)) % MOD;

                // Update 'max_sum'
                max_sum = max(max_sum, contribution);
            }
        }

        cout << max_sum << endl;
    }
    return 0;
}
