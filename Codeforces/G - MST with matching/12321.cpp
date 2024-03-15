#include<iostream>
#include<cstring>
#include<vector>
#include<array>
#include<numeric>
#include<algorithm>
using namespace std;
using LL = long long;

struct DSU{
   vector<int> p;
   DSU(int n) : p(n + 1){
      iota(p.begin(), p.end(), 0);
   }

   int find(int x){
      return p[x] == x ? x : p[x] = find(p[x]);
   }

   bool same(int x, int y) { 
      return find(x) == find(y); 
   }

   bool merge(int x, int y){
      x = find(x), y = find(y);
      if (x == y) return false;
      p[y] = x;
      return true;
   }
};

int main(){

#ifdef LOCAL
   freopen("data.in", "r", stdin);
   freopen("data.out", "w", stdout);
#endif

   cin.tie(0);
   cout.tie(0);
   ios::sync_with_stdio(0);

   const int INF = 0x3f3f3f3f;
   int n, c;
   cin >> n >> c;
   vector<array<int, 3> > p;
   p.reserve(n * n);
   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         int x;
         cin >> x;
         if (x != 0 && i < j){
               p.push_back({x, i, j});
         }
      }
   }
   sort(p.begin(), p.end());
   int ans = INF;
   for(int i = 1; i < 1 << n; i++){
      int s = __builtin_popcount(i) * c;
      DSU dsu(n);
      int cnt = 0;
      for(auto [w, a, b] : p){
         if ((i >> a & 1) || (i >> b & 1)){
               if (dsu.merge(a, b)){
                  s += w;
                  cnt += 1;
               }
         }
      }
      if (cnt == n - 1){
         ans = min(ans, s);
      }
   }
   cout << ans << '\n';

}