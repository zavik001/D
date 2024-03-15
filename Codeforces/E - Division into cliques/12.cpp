#include<bits/stdc++.h>

using namespace std;

#define int long long 
#define pb push_back
#define F first 
#define S second 

const int mol=1e9+7, b=137;

int ans[45], pos[45];
void solve(){
   int n, k;
   cin>>n>>k;
   int pp=(n+k-1)/k;
   int id=1;
   int num;
   vector<int>tot;
   for(int i=(k+1)/2-1;i>=1;i--) tot.pb(i);
   for(int i=k;i>(k+1)/2-1;i--) tot.pb(i);
   int iu=1;
   for(id=1;id+k-1<=n;id+=k){
      num=k;int hh=0;
      for(int j=id;j<id+k;j++){
         pos[j]=iu;
         ans[j]=k*(iu-1)+tot[hh++];
      }
      iu++;
   }
   
   k=n-id+1;
   tot.clear();
   for(int i=(k+1)/2-1;i>=1;i--) tot.pb(i);
   for(int i=k;i>(k+1)/2-1;i--) tot.pb(i);
   int ii=0;
   for(int j=id;j<=n;j++){
      pos[j]=iu;  
      ans[j]=tot[ii++]+id-1;
   }
   for(int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<"\n"<<pp<<"\n";
   for(int i=1;i<=n;i++) cout<<pos[i]<<" ";cout<<"\n";
}

signed main(){
   ios::sync_with_stdio(0);cin.tie(0);
   int t;
   cin>>t;
   while(t--)
   solve();
   return 0;
}