#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int Dijkstra(vector<vector<pair<int, int>>> G, int S, int F)
{
   int N = G.size();
   vector<bool> A(N, false);
   vector<int> B(N, INT_MAX);

   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
   B[S] = 0;
   Q.push({ 0, S });

   while (!Q.empty())
   {
      int v = Q.top().second;
      Q.pop();

      if (A[v])
         continue;
      A[v] = true;

      for (auto u : G[v])
      {
         int x = u.first, y = u.second;

         if (x + B[v] < B[y])
         {
            B[y] = x + B[v];
            Q.push({ B[y], y });
         }
      }
   }
   return (B[F] == INT_MAX) ? -1 : B[F];
}

int main()
{
   int N = 0, S = 0, F = 0;

   cin >> N >> S >> F;

   vector<vector<pair<int, int>>> G(N + 1);

   for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
      {
         int x = 0;

         cin >> x;

         if (x != -1 && i != j)
            G[i].push_back({ x, j });
      }

   cout << Dijkstra(G, S, F);

   return 0;
}
