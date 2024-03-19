#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		cout<<(c/a)+(c/b)+2<<endl;
	}
}