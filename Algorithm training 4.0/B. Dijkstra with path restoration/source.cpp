#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void Dijkstra(vector<vector<pair<int, int>>> G, int S, int F)
{
   int N = G.size();
   vector<bool> A(N, false);
   vector<int> B(N, INT_MAX);
   vector<int> C(N);

   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
   B[S] = 0;
   C[S] = S;
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
            C[y] = v;
            Q.push({ B[y], y });
         }
      }
   }
   if (B[F] == INT_MAX)
      cout << -1;
   else
   {
      vector<int> P;
      for (int v = F; v != S; v = C[v])
         P.push_back(v);
      P.push_back(S);
      for (int i = 0; i < P.size(); i++)
         cout << P[P.size()- 1 - i] << " ";
   }
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

         if (x != -1)
            G[i].push_back({ x, j });
      }

   Dijkstra(G, S, F);

   return 0;
}
