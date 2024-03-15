#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector< vll > vll2;
typedef pair<ll, ll> pll;
typedef string str;

//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define rand(l, r) uniform_int_distribution<ll>(l, r)(rng)

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr)
#define vin(a) {for (auto& _ : (a)) {cin >> _;}}
#define vout(a) {for (auto _ : (a)) {cout << _ << " ";} cout << "\n";}
#define all(x) (x).begin(), (x).end()
#define sz(a) int((a).size())

#define F first
#define S second
#define pb push_back

const int inf = 1e9, mod = 1e9+7, N = 1e5, LG = 30;
const ll INF = 1e18;
const ld eps = 1e-9;


int solve() {
   str s; cin >> s;

   auto check = [&] (ll half) {
      int len = 0;
      for (int i = 0; i+half < sz(s); ++i) {
         if (s[i] == '?' || s[i+half] == '?' || s[i] == s[i+half]) {
               ++len;
         } else {
               len = 0;
         }
         if (len == half) {
               return true;
         }
      }
      return false;
   };

   for (int half = sz(s)/2; half > 0; --half) {
      if (check(half)) {
         cout << 2*half << "\n";
         return 0;
      }
   }

   cout << 0 << "\n";
   return 0;

   return 0;
}

int main() {
   IOS;
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

   ll tc = 1;
   cin >> tc;
   while (tc--) {
      solve();
   }

   return 0;
}
