#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstdint>
using namespace std;

int64_t Dijkstra(vector<vector<pair<int64_t, int64_t>>> G, int64_t S, int64_t F)
{
   int64_t N = G.size();
   vector<bool> A(N, false);
   vector<int64_t> B(N, INT64_MAX);

   priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>>> Q;
   B[S] = 0;
   Q.push({ 0, S });

   while (!Q.empty())
   {
      int64_t v = Q.top().second;
      Q.pop();

      if (A[v])
         continue;
      A[v] = true;

      for (auto u : G[v])
      {
         int64_t x = u.first, y = u.second;

         if (x + B[v] < B[y])
         {
            B[y] = x + B[v];
            Q.push({ B[y], y });
         }
      }
   }
   return (B[F] == INT64_MAX) ? -1 : B[F];
}

int main()
{
   int64_t N = 0, K = 0;

   cin >> N >> K;

   vector<vector<pair<int64_t, int64_t>>> G(N + 1);

   for (int64_t i = 1; i <= K; i++)
   {
      int64_t x = 0, y = 0, z = 0;
      cin >> x >> y >> z;
      G[x].push_back({ z, y });
      G[y].push_back({ z, x });
   }

   int64_t A = 0, B = 0;
   cin >> A >> B;

   cout << Dijkstra(G, A, B);

   return 0;
}
