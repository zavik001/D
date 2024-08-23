#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

long long solve(vector<vector<int>>& sequences, int m) {
    set<int> all_elements;
    
    // Объединяем все элементы из всех последовательностей
    for (const auto& seq : sequences) {
        for (int num : seq) {
            all_elements.insert(num);
        }
    }
    
    // Нахождение максимального числа, которое можно достичь
    int mex = 0;
    while (all_elements.find(mex) != all_elements.end()) {
        mex++;
    }
    
    // Если m <= mex, то сумма будет (m+1) * mex
    if (m <= mex) {
        return (m + 1) * mex;
    }
    // Иначе сумма будет (mex * (mex + 1)) + (m - mex + 1) * (mex + 1)
    return (long long)mex * (mex + 1) + (m - mex + 1) * (mex + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> sequences(n);
        for (int i = 0; i < n; ++i) {
            int l;
            cin >> l;
            sequences[i].resize(l);
            for (int j = 0; j < l; ++j) {
                cin >> sequences[i][j];
            }
        }

        cout << solve(sequences, m) << endl;
    }

    return 0;
}
