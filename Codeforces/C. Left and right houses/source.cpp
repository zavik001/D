
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+10;
int a[N],sum[N];
int t;
signed main(){	
   ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		for(int i=0;i<n;i++){
			sum[i+1]=sum[i]+s[i]-'0';
		}
		int ans1=0x3f3f3f3f,ans2=0x3f3f3f3f;
		for(int i=n/2;i>=0;i--){
			if(sum[i]*2<=i&&(sum[n]-sum[i])*2>=n-i) {
				ans1=i;
				break;
			}
		}
		for(int i=n/2+1;i<=n;i++){
			if(sum[i]*2<=i&&(sum[n]-sum[i])*2>=n-i) {
				ans2=i;
				break;
			}
		}
		if(n%2){
			if(abs(n/2-ans1+0.5)<=abs(ans2-n/2-0.5)) cout<<ans1<<"\n";
			else cout<<ans2<<"\n";
		}
		else{
			if(abs(n/2-ans1)<=abs(ans2-n/2)) cout<<ans1<<"\n";
			else cout<<ans2<<"\n";
		}
	}
	return 0;
}