#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define vl vector<ll>
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define pb push_back
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   ll tests = 1;
   cin >> tests;
   while(tests--)
   {
      ll n, i, cnt1 = 0, cnt2 = 0;
      cin >> n;
      string s1, s2;
      cin >> s1;
      cin >> s2;
      if(n == 2)
         cout << "YES\n";
      else
      {
         queue<pll>q;
         ll vis[2][n+5];
         for(i = 0; i <= n+3; i++)
         {
               vis[0][i] = 0;
               vis[1][i] = 0;
         }
         q.push({0, 0});
         bool flag = false;
         while(!q.empty())
         {
               ll x = q.front().f, y = q.front().s;
               q.pop();
               ll a, b;
               vis[x][y] = 1;
               if(x == 1 && y >= n - 1)
               {
                  flag = true;
                  break;
               }
               else    if(y >= n)
                  continue;
               a = x, b = y;
               b++;
               if(b <= n - 1)
               {
                  if(a == 1)
                  {
                     if(s2[b] == '<')
                           b--;
                     else
                           b++;
                  }
                  if(a == 0)
                  {
                     if(s1[b] == '<')
                           b--;
                     else
                           b++;
                  }
                  if(vis[a][b] == 0 && b <= n){
                     q.push({a, b});
                     vis[a][b] = 1;
                  }
               }
               a = x, b = y;
               if(a == 1)
               {
                  if(s1[b] == '>')
                     b++;
                  else
                     b--;
               }
               if(a == 0)
               {
                  if(s2[b] == '>')
                     b++;
                  else
                     b--;
               }
               a = 1 - a;
               if(vis[a][b] == 0 && b <= n){
                  q.push({a, b});
                  vis[a][b] = 1;
               }
               a = x, b = y;
               b--;
               if(b >= 0)
               {
                  if(a == 0)
                  {
                     if(s1[b] == '>')
                           b++;
                     else
                           b--;
                  }
                  if(a == 1)
                  {
                     if(s1[b] == '>')
                           b++;
                     else
                           b--;
                  }
                  if(vis[a][b] == 0 && b <= n){
                     q.push({a, b});
                     vis[a][b] = 1;
                  }
               }
         }
         if(flag)
               cout << "YES\n";
         else
               cout << "NO\n";
      }
   }
}