#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string rearrangeString(const string &s) {
    vector<int> freq(26, 0);

    // Подсчёт частоты символов
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Создание пары (символ, частота) и сортировка по частоте
    vector<pair<int, char>> freqCharPairs;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            freqCharPairs.push_back({freq[i], 'a' + i});
        }
    }
    sort(freqCharPairs.rbegin(), freqCharPairs.rend()); // Сортировка по убыванию частоты

    // Используем вектор для размещения символов
    string result(s.size(), ' '); // Изначально строка заполняется пробелами
    int index = 0;

    // Распределяем символы по строке
    for (const auto &pair : freqCharPairs) {
        int count = pair.first;
        char ch = pair.second;

        for (int i = 0; i < count; ++i) {
            result[index] = ch;
            index += 2;
            if (index >= s.size()) {
                index = 1; // Если дошли до конца строки, начинаем заполнять нечетные позиции
            }
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        string result = rearrangeString(s);
        cout << result << endl;
    }
    return 0;
}
