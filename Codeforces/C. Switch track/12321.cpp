#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
bool can[maxn][2];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string a,b;
		scanf("%d",&n);
		cin>>a>>b;
		if(n==2)
		{
			printf("YES\n");
			continue;
		}
		if(a[1]=='<') can[0][0]=1;
		else if(a[1]=='>') can[2][0]=1;
		can[1][1]=1;
		for(int i=1;i<=n;i++)
		{
			if(can[i-1][0]&&a[i]=='>') can[i+1][0]=1;
			if(can[i][1]&&a[i]=='>') can[i+1][0]=1;
			if(can[i][1]&&a[i]=='<') can[i-1][0]=1;
			
			if(can[i-1][1]&&b[i]=='>') can[i+1][1]=1;
			if(can[i][0]&&b[i]=='>') can[i+1][1]=1;
			if(can[i][0]&&b[i]=='<') can[i-1][1]=1;
			
		}
		if(can[n-1][1])
		{
			printf("YES\n");
		}
		else printf("NO\n");
		for(int i=0;i<=n;i++)
		for(int j=0;j<=1;j++)
		can[i][j]=0;
	}
	return 0;
}