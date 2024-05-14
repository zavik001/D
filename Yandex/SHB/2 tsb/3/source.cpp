#include<bits/stdc++.h>
using namespace std;

struct elem_G {int t, v; elem_G(int _t, int _v) : t(_t), v(_v) {}};

struct elem_K {int v1, v2, t, c, n; elem_K(int _v1, int _v2, int _t, int _c, int _n) : v1(_v1), v2(_v2), t(_t), c(_c), n(_n) {}};

struct elem_P {int v1, v2, t; elem_P(int _v1, int _v2, int _t) : v1(_v1), v2(_v2), t(_t) {}};

bool djkstra(vector<vector<elem_G>> &G, elem_P p) 
{
   int v1 = p.v1, v2 = p.v2, t = p.t;

   size_t n = G.size();
   vector<bool> A(n, false);
   vector<int> dist(n, numeric_limits<int>::max());
   dist[v1] = 0;

   for (int i = 0; i < n; ++i) 
   {
      int min_dist = numeric_limits<int>::max();
      int u = -1;
      for (int j = 0; j < n; ++j) {
         if (!A[j] && dist[j] < min_dist) 
         {
            min_dist = dist[j];
            u = j;
         }
      }

      if (u == -1 || u == v2) 
         break;

      A[u] = true;

      for (const auto &neighbor : G[u]) 
      {
         int v = neighbor.v;
         int weight = neighbor.t;
         if (!A[v] && dist[u] + weight < dist[v]) 
         {
            dist[v] = dist[u] + weight;
         }
      }
   }

   return dist[v2] <= t;
}

bool check(vector<vector<elem_G>> &G, vector<elem_K> &K, vector<elem_P> &P, int m)
{
   vector<pair<int, int>> addedEdges;

   for (int i = 0; i <= m; i++)
   {
      G[K[i].v1].push_back(elem_G{K[i].t, K[i].v2});
      G[K[i].v2].push_back(elem_G{K[i].t, K[i].v1});
      addedEdges.push_back({K[i].v1, K[i].v2});
   }

   for (int i = 0; i < P.size(); i++)
   {
      if (djkstra(G, P[i]) == false)
      {
         for (const auto &edge : addedEdges)
         {
            G[edge.first].pop_back();
            G[edge.second].pop_back();
         }
         return false;
      }
   }

   for (const auto &edge : addedEdges)
   {
      G[edge.first].pop_back();
      G[edge.second].pop_back();
   }

   return true;
}

int main ()
{
   int N = 0, M = 0;
   cin >> N >> M;
   vector<vector<elem_G>> G(N);
   for(int i = 0; i < M; i++)
   {
      int v1 = 0, v2 = 0, t = 0;
      cin >> v1 >> v2 >> t;

      G[v1-1].push_back(elem_G{t, v2 - 1});
      G[v2-1].push_back(elem_G{t, v1 - 1});
   }

   int k = 0;
   cin >> k;
   vector<elem_K> K(k, elem_K{0, 0, 0, 0, 0}); 
   for(int i = 0; i < k; i++)
   {
      int v1 = 0, v2 = 0, t = 0, c = 0;
      cin >> v1 >> v2 >> t >> c;

      K[i] = elem_K{v1 - 1, v2 - 1, t, c, i};
   }

   int p = 0;
   cin >> p;
   vector<elem_P> P(p, elem_P{0, 0, 0}); 
   for(int i = 0; i < p; i++)
   {
      int v1 = 0, v2 = 0, t = 0;
      cin >> v1 >> v2 >> t;

      P[i] = elem_P{v1 - 1, v2 - 1, t};
   }

   sort(K.begin(), K.end(), [](const elem_K &a, const elem_K &b){return a.c < b.c ;});

   int l = -1, r = k - 1, min_ = -3;
   while(l <= r)
   {
      int m = l + (r - l) / 2;
      if (check(G, K, P, m))
      {
         min_ = m;
         r = m - 1;
      }
      else 
         l = m + 1;
   }

   if (min_ == -3)
   {
      cout << -1;
      return 0;
   }

   if (min_ == -1)
   {
      cout << 0;
      return 0;
   }
   
   int x = K[min_].c;
   vector<elem_K> A;
   for (int i = 0; i < k; i++)
      if (K[i].c <= x) A.push_back(K[i]);
   
   sort(A.begin(), A.end(), [](const elem_K &a, const elem_K &b){return a.n < b.n; });

   size_t n = A.size();
   cout << n << '\n';
   for (int i = 0; i < n; i++)
      cout << A[i].n + 1 << " ";

   return 0;
}