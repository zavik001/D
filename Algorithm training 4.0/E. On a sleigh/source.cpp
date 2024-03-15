#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <limits>

using namespace std;

vector<double> Bfs(vector<pair<double, double>> G1, vector<vector<pair<double, double>>> G2, int V)
{
   int N = G1.size() - 1;
   double speed = G1[V].second;
   vector<double> A(N + 1, std::numeric_limits<int>::max());
   vector <bool> B(N + 1, false);
   queue<int> Q;


   A[V] = G1[V].first;
   Q.push(V);


   for (; !Q.empty(); )
   {
      int u = Q.front();
      Q.pop();

      if (B[u])
         continue;

      B[u] = true;

      for (auto w : G2[u])
      {
         double k = w.first, y = A[u];
         double t = 0;
         t = y + static_cast<double>(k) * (1. / speed);
         if (t < A[w.second])
         {
            A[w.second] = t;
            Q.push(w.second);
         }
      }
   }

   return A;
}


void Djikstra(vector<vector<double>> G3)
{
   int N = G3.size();
   vector<double> dist(N, std::numeric_limits<double>::max());
   vector<int> prev(N, -1);
   vector<bool> visited(N, false);
   dist[1] = 0;

   for (int i = 0; i < N - 1; i++)
   {
      int u = -1;
      for (int j = 1; j < N; j++)
      {
         if (!visited[j] && (u == -1 || dist[j] < dist[u]))
            u = j;
      }

      if (dist[u] == std::numeric_limits<double>::max())
         break;

      visited[u] = true;

      for (int v = 1; v < N; v++)
      {
         if (G3[u][v] != std::numeric_limits<double>::max() && dist[u] + G3[u][v] < dist[v])
         {
            dist[v] = dist[u] + G3[u][v];
            prev[v] = u;
         }
      }
   }

   int max_dist_vertex = 1;
   for (int i = 2; i < N; i++)
   {
      if (dist[i] > dist[max_dist_vertex])
         max_dist_vertex = i;
   }

   cout << fixed << setprecision(10) << dist[max_dist_vertex] << endl;

   vector<int> path;
   for (int v = max_dist_vertex; v != -1; v = prev[v])
      path.push_back(v);


   for (int v : path)
      cout << v << " ";
   cout << endl;
}



int main()
{
   int N = 0;
   cin >> N;

   vector <pair<double, double>> G1(N + 1);
   for (int i = 1; i < N + 1; i++)
      cin >> G1[i].first >> G1[i].second;


   vector<vector<pair<double, double>>> G2(N + 1);
   for (int i = 1; i < N; i++)
   {
      int v1 = 0, v2 = 0, s = 0;
      cin >> v1 >> v2 >> s;

      G2[v1].push_back({ s, v2 });
      G2[v2].push_back({ s, v1 });
   }

   vector<vector<double>> G3(N + 1, vector<double>(N + 1));

   for (int i = 1; i < N + 1; i++)
   {
      vector<double> B = Bfs(G1, G2, i);
      for (int j = 1; j < N + 1; j++)
      {
         G3[j][i] = B[j];
      }
   }


   Djikstra(G3);

   return 0;
}