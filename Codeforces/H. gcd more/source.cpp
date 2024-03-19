//https://codeforces.com/contest/1945/problem/H
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;
int gcd(int a,int b)
{
	while(b)
	{
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int N,X,A[4<<17];
bool intst[4<<17];
int pc[20];
bool check(int i,int j)
{
	assert(i!=j);
	int g=gcd(A[i],A[j]);
	int a=0;
	for(int k=0;k<20;k++)
	{
		if(pc[k]-(A[i]>>k&1)-(A[j]>>k&1)==N-2)a|=1<<k;
	}
	return g>a+X;
}
vector<int>idx[4<<17];
pair<int,int>solve()
{
	cin>>N>>X;
	for(int k=0;k<20;k++)pc[k]=0;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		intst[i]=false;
		for(int k=0;k<20;k++)if(A[i]>>k&1)pc[k]++;
	}
	for(int k=0;k<20;k++)if(pc[k]==N-1||pc[k]==N-2)
	{
		for(int i=0;i<N;i++)if(!(A[i]>>k&1))intst[i]=true;
	}
	for(int i=0;i<N;i++)if(intst[i])
	{
		for(int j=0;j<N;j++)if(i!=j)
		{
			if(check(i,j))return make_pair(i,j);
		}
	}
	int maxA=0;
	for(int i=0;i<N;i++)if(!intst[i])maxA=max(maxA,A[i]);
	for(int i=1;i<=maxA;i++)idx[i].clear();
	for(int i=0;i<N;i++)if(!intst[i])idx[A[i]].push_back(i);
	int a=0;
	for(int k=0;k<20;k++)if(pc[k]==N)a|=1<<k;
	for(int g=a+X+1;g<=maxA;g++)
	{
		int i=-1,j=-1;
		for(int k=g;k<=maxA;k+=g)
		{
			for(int id=0;id<idx[k].size()&&j==-1;id++)
			{
				if(i==-1)i=idx[k][id];
				else j=idx[k][id];
			}
		}
		if(j!=-1)
		{
			assert(check(i,j));
			return make_pair(i,j);
		}
	}
	return make_pair(-1,-1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		pair<int,int>p=solve();
		if(p.first==-1)cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			cout<<"2 "<<A[p.first]<<" "<<A[p.second]<<"\n";
			cout<<N-2;
			for(int i=0;i<N;i++)if(i!=p.first&&i!=p.second)cout<<" "<<A[i];
			cout<<"\n";
		}
	}
}
