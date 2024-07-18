#include <bits/stdc++.h>

using namespace std;

void printArray(int n){
    for (int i = 0; i < n; i++) {
        cout << i + 1;
        if (i < n-1) {
            cout << " ";
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 0;
    cin >> t;

    while(t--) {
        int n = 0;
        cin >> n;
        printArray(n);
    }

    return 0;
}