#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=505,Inf=1e9;
int n,k,a[N],Cnt[N];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		memset(Cnt,0,sizeof(Cnt));
		for(int i=1,x;i<=n;++i)cin>>x,++Cnt[x];
		while(1)
      {
			int Mx=-1,i1=0,Mn=Inf,i2=0;
			for(int i=1;i<=100;++i)
         {
				if(Cnt[i]<k)continue;
				if(Mn>Cnt[i])Mn=Cnt[i],i2=i;
		   }
			cout<<i2<<" ";
			if(!i2)break;
			Cnt[i2]-=k;
			for(int i=1;i<=100;++i)
         {
				if(Mx<Cnt[i])Mx=Cnt[i],i1=i;
			}
			cout<<i1<<"  ";
			Cnt[i1]+=k-1;
		}
		int Res=0;
		for(int i=1;i<=100;++i)Res+=Cnt[i];
		cout<<Res<<"\n";
	}
	return 0;
}