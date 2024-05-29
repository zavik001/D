#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int dfs(vector<vector<bool>>& graph, int start, int finish, int n) {
    stack<int> mystack;

    int q = 0, i = start;
    while (q == 0) {
        if (graph[i][finish] == 1)
            q = 1;
        else {
            for (int j = 0; j < n + 1; j++)
                if (i < n + 1 && j < n  + 1 && graph[i][j] == 1)
                    mystack.push(j);
            if (i < n+1)
            graph[i].clear();
            do {
                if (!mystack.empty()) {
                    i = mystack.top();
                    mystack.pop();
                }
                else q = -1;
            } while (i < n+1 && !size(graph[i]) && q != -1);
        }
    }
    return q;
}

int main() {
    int n, m;

    string s;
    cout << endl << "enter file name  ";
    cin >> s;
    ifstream fin(s);

    fin >> n >> m;

    vector<vector<bool>> graph(n+1, vector<bool>(n + 1, 0));

    for (int i = 0; i < m; ++i) {
        int a, b;
        fin >> a >> b;
        graph[a][b] = 1;
    }

    int start = 0, finish = 0;
    fin >> start >> finish;
    start;
    finish;

    fin.close();

    auto start_time = high_resolution_clock::now();
    int dist = dfs(graph, start, finish, n);
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    cout << "Время, затраченное на DFS: " << duration.count() << " мс" << endl;

    if (dist == 1)
        cout << endl << "путь существует" << endl;
    else
        cout << endl << "путь не существует" << endl;
    return 0;
}