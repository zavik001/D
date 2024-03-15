#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//#pragma GCC optimization("g", on)
//#pragma GCC optimization("03")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("inline")
//#pragma GCC optimize("-fgcse,-fgcse-lm")
//#pragma GCC optimize("-ftree-pre,-ftree-vrp")
//#pragma GCC optimize("-ffast-math")
//#pragma GCC optimize("-fipa-sra")
//#pragma GCC optimize("-fpeephole2")
//#pragma GCC optimize("-fsched-spec")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")

#define aboba ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define br break;
#define sp " "
#define en "\n"
#define pb push_back
#define sz(a) int(a.size())
#define bg begin()
#define ed end()
#define in insert
#define ss second
#define ff first
#define setp(a) cout << fixed; cout << setprecision(a)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef double db;
typedef tree<
   long long,
   null_type,
   less_equal<long long>,
   rb_tree_tag,
   tree_order_statistics_node_update> orset;

void freopen(string s) { freopen((s + ".in").c_str(), "r", stdin); freopen((s + ".out").c_str(), "w", stdout); }
ll bm(ll x, ll y, ll z) { ll res = 0; while (y) { if (y & 1) (res += x) %= z; (x += x) %= z; y >>= 1; } return res; }
ll bp(ll x, ll y, ll z) { ll res = 1; x %= z; while (y) { if (y & 1) { (res *= x) %= z; y--; } (x *= x) %= z; y >>= 1; } return res; }
// C(n, k) = ((fact[n] * bp(fact[k], mod - 2)) % mod * bp(fact[n - k], mod - 2)) % mod;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }

const ll N = 2e5 + 11;
const ll inf = 1e9 + 7;
ll tt = 1;
bool u[N];

void solve() {
string s; cin >> s;
ll n = sz(s);
s = ' ' + s;
ll mx = 0;
for (int k = n / 2;k >= 1;k--) {
   ll cnt = 0;
   for (int i = 1;i <= n;i++) {
      if (i + k > n) u[i] = 0;
      else {
         char a = s[i], b = s[i + k];
         if (a == '?' || b == '?') a = b;
         u[i] = (a == b);
      }
      if (u[i]) {
         cnt++;
         if (cnt == k) {
            cout << k * 2 << en;
            return;
         }
      } else cnt = 0;
   }
}
cout << 0 << en;
}

int main() {      
   aboba    
   // freopen("haircut"); 
   // precalc();	
   cin >> tt;
   for (int i = 1;i <= tt;i++) {			
   solve();
   }
}