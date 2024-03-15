#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;
const int mod = 998244353;

using namespace std;

int pw(int x, int n) {
   int res = 1;
   while (n > 0) {
      if (n & 1) {
         res = res * 1ll * x % mod;
      }
      n /= 2;
      x = 1ll * x * x % mod;
   }
   return res;
}

int fac[N];
int inv[N];
int p2[N];

int C(int n, int k) {
   return 1ll * fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void add(int &x, int y) {
   x += y;
   if (x >= mod) {
      x -= mod;
   }
}

int n, q;
int a[N];
int b[N];
int f[N];

int main() {
   ios_base::sync_with_stdio(0);

   fac[0] = 1;
   for (int i = 1; i < N; i++) {
      fac[i] = 1ll * fac[i - 1] * i % mod;
   }
   inv[N - 1] = pw(fac[N - 1], mod - 2);
   for (int i = N - 2; i >= 0; i--) {
      inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
   }

   int inv_2 = pw(2, mod - 2);
   p2[0] = 1;
   for (int i = 1; i < N; i++) {
      p2[i] = 1ll * p2[i - 1] * inv_2 % mod;
   }

   cin >> n >> q;
   for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] += a[i - 1];
   }
   for (int i = 1; i <= n; i++) {
      cin >> b[i];
      b[i] += b[i - 1];
   }

   int S = b[n];
   for (int i = 0; i <= S; i++) {
      f[i] = C(S, i);
      if (i > 0) {
         add(f[i], f[i - 1]);
      }
   }

   for (int i = 1; i <= q; i++) {
      int l, r;
      cin >> l >> r;
      int g1 = a[r] - a[l - 1];
      int g2 = a[n] - g1;
      int s1 = b[r] - b[l - 1];

      int shit = g1 - g2 + s1;
      
      if (shit <= 0) {
         cout << 0 << " ";
      } else if (shit > S) {
         cout << 1 << " ";
      } else {
         cout << f[shit - 1] * 1ll * p2[S] % mod << " ";
      }
   }

   return 0;
}