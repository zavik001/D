using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define el " \n"
#define uv 	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
#include<dbg.h>
#else
#define debug(...);
#endif
   
void solve() {
   ll n;
   cin>>n;
   vector<vector<char>> a(2,vector<char>(n));
   vector<vector<ll>> vis(2,vector<ll>(n));

   for (ll i = 0; i < n; i++)
   {
      cin>>a[0][i];
   }
   for (ll i = 0; i < n; i++)
   {
      cin>>a[1][i];
   }
   auto val=[&](ll x,ll y)
   {
      return (0<=x && x<2 && 0<=y && y<n);
   };
   vector<vector<ll>> tmp={{0,1},{1,0},{-1,0},{0,-1}};
   ll tst=0;

   function<void(ll,ll)> dfs=[&](ll x,ll y)
   {
      if(x==1 && y==n-1)
      { 
         tst=1;
      }
      vis[x][y]=1;
      for (int i = 0; i < 4; i++)
      {
         ll nx=x+tmp[i][0],ny=y+tmp[i][1];
         if(!val(nx,ny))continue;
         if(a[nx][ny]=='>')
         ny++;
         else ny--;
         if(vis[nx][ny])continue;
         dfs(nx,ny);

      }
      
   };
   dfs(0,0);
   cout<<(tst?"YES":"NO")<<el;
}

int main() {
   uv
   int tt=1;
   cin>>tt;
   while(tt--)
   {
   solve();
   }

   return 0;
}