   #include <bits/stdc++.h>

   #ifdef LOCAL
   #include "debug.h"
   #else
   #define debug(...)
   #endif


   #define ff first
   #define ss second
   #define range(x) std::begin(x), std::end(x)

   using i64 = long long;
   using u32 = unsigned int;
   using u64 = unsigned long long;
   using pii = std::pair<int, int>;
   using vi = std::vector<int>;
   using vvi = std::vector<vi>;
   using vl = std::vector<i64>;
   using vp = std::vector<pii>;
   using vs = std::vector<std::string>;
   template <typename T> using Heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;


   #include <ext/pb_ds/assoc_container.hpp>
   #include <ext/pb_ds/priority_queue.hpp>

   namespace __gnu_pbds {
   template <typename Key, typename Val, typename Comp = std::less<Key>>
   using ordered_map = tree<Key, Val, Comp, rb_tree_tag, tree_order_statistics_node_update>;
   template <typename T, typename Comp = std::less<T>> using ordered_set = ordered_map<T, null_type, Comp>;
   template <typename T> using ordered_multiset = ordered_set<T, std::less_equal<T>>;
   template <typename T, typename Comp = std::greater<T>> using FastHeap = priority_queue<T, Comp, thin_heap_tag>;
   template <typename T, typename Comp = std::greater<T>> using JoinHeap = priority_queue<T, Comp, pairing_heap_tag>;
   }  // namespace __gnu_pbds
   using __gnu_pbds::FastHeap;
   using __gnu_pbds::JoinHeap;
   using __gnu_pbds::ordered_map;
   using __gnu_pbds::ordered_multiset;
   using __gnu_pbds::ordered_set;


   template <typename T> bool chkmin(T& lhs, const T& rhs) { return lhs > rhs ? lhs = rhs, true : false; }
   template <typename T> bool chkmax(T& lhs, const T& rhs) { return lhs < rhs ? lhs = rhs, true : false; }
   template <typename T> T lowbit(T x) { return x & -x; }

   template <unsigned int P> struct Fp {
   unsigned int v = 0;

   // reflection
   template <typename T = int> static constexpr T mod() { return P; }
   template <typename T = int> constexpr T val() { return v; }

   // constructor
   constexpr Fp() = default;
   template <typename T> constexpr Fp(T x) : v(x % mod()) {
      if constexpr (std::is_signed_v<T>)
      if (v >> 31) v += P;
   }

   // io
   friend std::istream& operator>>(std::istream& is, Fp& rhs) {
      long long v;
      is >> v;
      rhs = v;
      return is;
   }
   friend std::ostream& operator<<(std::ostream& os, Fp rhs) { return os << rhs.v; }

   // comparision
   friend constexpr bool operator==(Fp lhs, Fp rhs) { return lhs.v == rhs.v; }
   friend constexpr bool operator!=(Fp lhs, Fp rhs) { return lhs.v != rhs.v; }

   // arithmetic
   constexpr Fp& operator+=(Fp rhs) {
      v += rhs.v;
      if (v >= P) v -= P;
      return *this;
   }
   constexpr Fp& operator-=(Fp rhs) {
      v -= rhs.v;
      if (v >> 31) v += P;
      return *this;
   }
   constexpr Fp& operator*=(Fp rhs) {
      v = static_cast<unsigned long long>(v) * rhs.v % P;
      return *this;
   }
   constexpr Fp& operator/=(Fp rhs) {
      v = fpow(rhs.v, P - 2, v);
      return *this;
   }
   template <typename T> constexpr Fp& operator^=(T rhs) {
      v = fpow(v, rhs);
      return *this;
   }
   friend constexpr Fp operator+(Fp lhs, Fp rhs) { return lhs += rhs; }
   friend constexpr Fp operator-(Fp lhs, Fp rhs) { return lhs -= rhs; }
   friend constexpr Fp operator*(Fp lhs, Fp rhs) { return lhs *= rhs; }
   friend constexpr Fp operator/(Fp lhs, Fp rhs) { return lhs /= rhs; }
   template <typename T> friend constexpr Fp operator^(Fp lhs, T rhs) { return lhs ^= rhs; }
   constexpr Fp operator+() const { return *this; }
   constexpr Fp operator-() const { return Fp{} - *this; }
   constexpr Fp operator~() const { return fpow(v, P - 2); }
   template <typename T> constexpr Fp pow(T exp) const { return fpow(v, exp); }

   // x^y * z
   template <typename T> static constexpr unsigned int fpow(unsigned long long x, T y, unsigned long long z = 1) {
      unsigned int n = y % (mod() - 1);
      if constexpr (std::is_signed_v<T>)
      if (n >> 31) n += P - 1;
      for (; n; n /= 2) {
      if (n & 1) z = z * x % P;
      x = x * x % P;
      }
      return z;
   }
   };

   using Z353 = Fp<998244353>;
   using Z007 = Fp<1000000007>;
   using Z009 = Fp<1000000009>;

   template <typename Z> struct Combination {
   static inline std::vector<Z> inv{0, 1}, fac{1, 1}, fiv{1, 1};
   static inline int N = 2;
   static void fix(int n) {
      if (N >= n) return;
      inv.resize(n);
      fac.resize(n);
      fiv.resize(n);
      for (int i = N; i < n; ++i) {
      inv[i] = inv[Z::mod() % i] * (Z::mod() - Z::mod() / i);
      fac[i] = fac[i - 1] * i;
      fiv[i] = fiv[i - 1] * inv[i];
      }
      N = n;
   }
   static Z inverse(int n) {
      fix(n + 1);
      return inv[n];
   }
   static Z factorial(int n) {
      fix(n + 1);
      return fac[n];
   }
   static Z facinv(int n) {
      fix(n + 1);
      return fiv[n];
   }
   static Z C(int n, int m) {
      fix(n + 1);
      return fac[n] * fiv[m] * fiv[n - m];
   }
   };


   template <typename T> struct Fenwick {
   std::vector<T> a;
   int n = 0;
   Fenwick() = default;
   Fenwick(int n, T x = T()) : a(n, x), n(n) {}
   void update(int p, T x) {
      for (int i = p; i < n; i |= i + 1) a[i] += x;
   }
   T sum_pre(int p) const {
      T x = T();
      for (int i = p; ~i; i = (i & (i + 1)) - 1) x += a[i];
      return x;
   }
   T sum(int l, int r) const { return sum_pre(r) - sum_pre(l - 1); }
   };

   template <typename T> struct FenwickV2 {
   std::vector<T> a, b;
   int n = 0;
   FenwickV2() = default;
   FenwickV2(int n) : a(n), b(n), n(n) {}
   void add_suf(int p, T x) {
      T y = x * p;
      for (int i = p; i < n; i |= i + 1) {
      a[i] += x;
      b[i] += y;
      }
   }
   void add(int l, int r, T x) {
      add_suf(l, x);
      add_suf(r + 1, -x);
   }
   T sum_pre(int p) {
      T x = T();
      for (int i = p++; ~i; i = (i & (i + 1)) - 1) x += a[i] * p - b[i];
      return x;
   }
   T sum(int l, int r) { return sum_pre(r) - sum_pre(l - 1); }
   };


   void initialize();
   void solution(int cas);

   int main() {
   initialize();
   int T = 1;
   // std::cin >> T;
   for (int cas = 1; cas <= T; ++cas) {
      solution(cas);
   }
   }


   void initialize() {
   std::cin.tie(nullptr)->sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(10);
   }


   void solution(int cas) {
   int n, c;
   std::cin >> n >> c;
   int w[20][20];
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
      std::cin >> w[i][j];
      }
   }

   std::vector<std::tuple<int, int, int>> E;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
      if (w[i][j]) E.emplace_back(w[i][j], i, j);
      }
   }
   std::sort(range(E));

   vi dsu(n);
   auto find = [&](auto&& find, int u) -> int {
      return u == dsu[u] ? u : dsu[u] = find(find, dsu[u]);
   };
   auto merge = [&](int u, int v) -> bool {
      u = find(find, u);
      v = find(find, v);
      if (u == v) return false;
      dsu[u] = v;
      return true;
   };

   int ans = 1 << 30;
   for (int s = 1; s < (1 << n); ++s) {
      if (__builtin_popcount(s) > n / 2) continue;
      std::iota(range(dsu), 0);
      int cur = __builtin_popcount(s) * c, cnt = 0;
      for (auto [e, u, v] : E) {
      if (((s >> u | s >> v) & 1) && merge(u, v)) {
         cur += e;
         cnt += 1;
      }
      }
      if (cnt == n - 1) chkmin(ans, cur);
   }

   std::cout << ans << '\n';
   }
