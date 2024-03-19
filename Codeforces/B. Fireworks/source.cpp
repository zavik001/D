#include <bits/stdc++.h>

using namespace std;

int main() 
{
   cin.tie(nullptr)->sync_with_stdio(false);
   cout << fixed << setprecision(10);

   int _;
   cin >> _;
   while (_--) 
   {
      long long a, b, m;
      cin >> a >> b >> m;
      cout << m / a + 1 + m / b + 1 << '\n';
   }
   return 0;
}