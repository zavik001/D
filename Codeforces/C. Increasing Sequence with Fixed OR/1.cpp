#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t; // количество тестов
    
    while (t-- > 0) {
        long long n;
        cin >> n; // читаем значение n для текущего теста
        
        vector<long long> longestSequence;
        
        for (long long start = n; start >= 1; start--) {
            vector<long long> currentSequence;
            currentSequence.push_back(start);
            
            for (long long i = start + 1; i <= n; i++) {
                long long last = currentSequence.back();
                if ((last | i) == n && i > last) {
                    currentSequence.push_back(i);
                }
            }
            
            if (currentSequence.size() > longestSequence.size()) {
                longestSequence = currentSequence;
            }
        }
        
        // Вывод результата
        cout << longestSequence.size() << endl;
        for (size_t i = 0; i < longestSequence.size(); i++) {
            cout << longestSequence[i];
            if (i < longestSequence.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
