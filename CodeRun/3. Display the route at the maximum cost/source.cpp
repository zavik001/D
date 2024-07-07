#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void printMaxWholeMeal(pair<int, string> arr) {
    cout << arr.first << endl;
    string path = arr.second;
    for (int i = 0; i < path.length(); i++) {
        cout << path[i];
        if (i < path.length() - 1) {
            cout << " ";
        }
    }
}

pair<int, string> FindMaxWholeMeal(vector<vector<pair<int, string>>>& arr) {
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j > 0) {
                arr[i][j] = make_pair(arr[i][j].first + arr[i][j-1].first, arr[i][j-1].second + "R");
            } else if (j == 0 && i > 0) {
                arr[i][j] = make_pair(arr[i][j].first + arr[i-1][j].first, arr[i-1][j].second + "D");
            } else if (i > 0 && j > 0) {
                int prevValue1 = arr[i-1][j].first;
                int prevValue2 = arr[i][j-1].first;
                if (prevValue1 > prevValue2) {
                    arr[i][j] = make_pair(arr[i][j].first + prevValue1, arr[i-1][j].second + "D");
                } else {
                    arr[i][j] = make_pair(arr[i][j].first + prevValue2, arr[i][j-1].second + "R");
                }
            }
        }
    }

    return arr[n-1][m-1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, string>>> arr(n, vector<pair<int, string>>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j].first;
        }
    }

    printMaxWholeMeal(FindMaxWholeMeal(arr));

    return 0;
}
