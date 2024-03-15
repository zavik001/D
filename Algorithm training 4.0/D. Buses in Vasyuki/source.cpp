#include <iostream>
#include <vector>
#include <queue>;
#include <cstdint>

using namespace std;

struct elem
{
   int32_t t1 = 0, t2 = 0, v2 = 0;
} ;


int32_t dijkstra(vector<vector<elem>> G, int32_t D, int32_t V)
{
   vector<int32_t> T(G.size(), INT32_MAX);
   vector<bool> A(G.size(), false);
   priority_queue<pair<int32_t, int32_t>, vector<pair<int32_t, int32_t>>, greater<pair<int32_t, int32_t>>> Q;
   T[D] = 0;
   Q.push({ 0, D});

   for (int i = 1; i < G.size(); i++)
   {
      int32_t a = Q.top().second;
      Q.pop();

      if (A[a])
         continue;

      A[a] = true;

      for (auto u : G[a])
      {
         elem e = u;
         if (T[a] <= e.t1 && e.t2 < T[e.v2])
         {
            T[e.v2] = e.t2;
            Q.push({e.t2, e.v2});
         }
      }
   }

   return T[V] == INT32_MAX ? -1: T[V];
}


int main()
{
   int32_t N = 0, d = 0, v = 0, R = 0;
   cin >> N >> d >> v >> R;

   vector <vector<elem>> G(N + 1);
   for (uint32_t i = 1; i < R + 1; i++)
   {
      elem e;
      int32_t v1 = 0;
      cin >> v1 >> e.t1 >> e.v2 >> e.t2;

      G[v1].push_back(e);
   }

   cout << dijkstra(G, d, v);

   return 0;
}