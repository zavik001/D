#include <bits/stdc++.h>
using namespace std;

int findMaxMove(vector<vector<int>> &matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - 1 >= 0 && j - 2 >= 0) {
                matrix[i][j] += matrix[i-1][j-2];
            }
            if (i - 2 >= 0 && j - 1 >= 0) {
                matrix[i][j] += matrix[i-2][j-1];
            }
        }
    }

    return matrix[n-1][m-1];
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    matrix[0][0] = 1;
    
    cout << findMaxMove(matrix, n, m);

    return 0;
}