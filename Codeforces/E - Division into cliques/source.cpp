   #include <bits/stdc++.h>

   #ifndef ONLINE_JUDGE
   #include "debug.cpp"
   #else
   #define debug(...)
   #endif

   using namespace std;


   vector<int> gen(int n) {
      vector<int> p(n);

      p[n / 2] = 0;
      for (int i = n / 2 - 1; i >= 0; --i) {
         p[i] = p[i + 1] + 1;
      }

      int v = p[0];
      for (int i = n - 1; i > n / 2; --i) {
         p[i] = ++v;
      }
      return p;
   }


   void solve() {
   int n, k; cin >> n >> k;
   k = min(k, n);
   vector<int> p = gen(k);
   vector<int> a(n);
   for (int i = 0; i < n / k * k; ++i) {
      int offset = i / k * k, pos = i % k;
      a[i] = p[pos] + offset;
   }

   if (n % k) {
      vector<int> q = gen(n % k);
      for (int i = n / k * k; i < n; ++i) {
         int offset = n / k * k, pos = i % k;
         a[i] = q[pos] + offset;
      }
   }

   for (int i = 0; i < n; ++i) {
      cout << a[i] + 1 << " \n"[i == n - 1];
   }

   cout << (n + k - 1) / k << '\n';
   for (int i = 0; i < n; ++i) {
      cout << i / k + 1 << ' ';
   }
   cout << '\n';
   }

   int main() {
   ios::sync_with_stdio(0); cin.tie(0);


   int T; cin >> T;
   for (int _ = 0; _ < T; ++_) {
      solve();
   }
   }
