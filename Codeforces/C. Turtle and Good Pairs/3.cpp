#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// Функция проверки возможности перестановки
bool is_possible(const vector<pair<int, int>>& segments, int n) {
    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1, 0);

    // Построение графа зависимостей
    for (const auto& seg : segments) {
        int l = seg.first, r = seg.second;
        for (int i = l; i < r; ++i) {
            graph[i].push_back(r);
            ++in_degree[r];
        }
    }

    // Топологическая сортировка
    queue<int> q;
    vector<int> topo_order;

    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (int v : graph[u]) {
            --in_degree[v];
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    return topo_order.size() == n;
}

// Функция подсчета инверсий
int count_inversions(const vector<int>& perm) {
    int n = perm.size();
    vector<int> fenwick(n + 1, 0);
    
    auto add = [&](int idx, int val) {
        while (idx <= n) {
            fenwick[idx] += val;
            idx += idx & -idx;
        }
    };
    
    auto query = [&](int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += fenwick[idx];
            idx -= idx & -idx;
        }
        return sum;
    };
    
    int inversions = 0;
    for (int i = n - 1; i >= 0; --i) {
        inversions += query(perm[i] - 1);
        add(perm[i], 1);
    }
    
    return inversions;
}

// Функция нахождения максимального количества инверсий
int max_inversions(int n, const vector<pair<int, int>>& segments) {
    if (!is_possible(segments, n)) {
        return -1;
    }

    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = n - i; // Ручное заполнение вектора значениями от n до 1
    }

    return count_inversions(perm);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<pair<int, int>> segments(m);
        for (int i = 0; i < m; ++i) {
            cin >> segments[i].first >> segments[i].second;
        }

        cout << max_inversions(n, segments) << endl;
    }
    
    return 0;
}
