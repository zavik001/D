#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool bfs(vector<vector<bool>>& graph, int start, int finish, int n) {
    vector<bool> visited(n + 1, false);
    queue<int> myqueue;
    myqueue.push(start);
    visited[start] = true;

    while (!myqueue.empty()) {
        int i = myqueue.front();
        myqueue.pop();

        if (i == finish)
            return true;

        for (int j = 0; j < n + 1; j++) {
            if (graph[i][j] && !visited[j]) {
                myqueue.push(j);
                visited[j] = true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;

    string s;
    cout << endl << "enter file name  ";
    cin >> s;
    ifstream fin(s);

    fin >> n >> m;

    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, 0));

    for (int i = 0; i < m; ++i) {
        int a, b;
        fin >> a >> b;
        graph[a][b] = 1;
    }

    int start, finish;
    fin >> start >> finish;
    start;
    finish;

    fin.close();

    auto start_time = high_resolution_clock::now();
    bool pathExists = bfs(graph, start, finish, n);
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    cout << "Time taken by BFS: " << duration.count() << " microseconds" << endl;

    if (pathExists)
        cout << endl << "the path exist" << endl;
    else
        cout << endl << "path does not exist" << endl;
    return 0;
}