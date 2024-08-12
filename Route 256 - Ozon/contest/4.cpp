#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--) {
        int n;
        cin >> n;
        cin.ignore(); 

        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        unordered_map<int, int> B;
        for (int i = 0; i < n; i++) {
            B[A[i]]++;
        }

        cin.ignore(); 
        string s;
        getline(cin, s);
        
        istringstream iss(s);
        vector<int> tokens;
        string token;
        bool flag = true;

        while (iss >> token) {
            try {
                int x = stoi(token);
                tokens.push_back(x);
            } catch (const invalid_argument &e) {
                flag = false;
                break;
            }
        }

        if (flag && tokens.size() == n) {
            vector<int> sortedTokens = tokens;
            sort(sortedTokens.begin(), sortedTokens.end());
            
            if (tokens != sortedTokens) {
                flag = false;
            }

            for (int num : tokens) {
                if (B.find(num) == B.end()) {
                    flag = false;
                    break;
                }
            }
        } else {
            flag = false;
        }

        if (flag) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
