#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+10;
int T,n,x,y,a[maxn];
ll ans;
int main(){
   scanf("%d",&T);
   while(T--){
      scanf("%d%d%d",&n,&x,&y);
      for(int i=1;i<=x;i++) scanf("%d",&a[i]);
      sort(a+1,a+x+1);
      if(x==2){
         printf("%d\n",min(n,3));
         continue;
      }
      ans=1ll*n*(n-1)/2-(n-x)-1ll*(x-2)*(x-1)/2;
      printf("%lld\n",ans);
   }
   return 0;
}
