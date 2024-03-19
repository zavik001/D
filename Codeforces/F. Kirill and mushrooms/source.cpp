//https://codeforces.com/contest/1945/problem/F
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;
//0-indexed
#include<vector>
#include<cassert>
template<typename T>
struct BIT{
	int N;
	vector<T>bit;
	BIT(int N_=0):N(N_),bit(N_){}
	T sum(int i)
	{
		assert(0<=i&&i<=N);
		T ans=0;
		for(;i>0;i-=i&-i)ans+=bit[i-1];
		return ans;
	}
	void add(int i,T a)
	{
		assert(0<=i&&i<N);
		i++;
		for(;i<=N;i+=i&-i)bit[i-1]+=a;
	}
	int lower_bound(T k)//k<=sum(ret)
	{
		if(k<=0)return 0;
		int ret=0,i=1;
		while((i<<1)<=N)i<<=1;
		for(;i;i>>=1)
		{
			if(ret+i<=N&&bit[ret+i-1]<k)
			{
				ret+=i;
				k-=bit[ret-1];
			}
		}
		return ret+1;
		//ret+1 == N+1 <=> sum<k
	}
};
int N,P[2<<17];
int inv[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		vector<pair<int,int> >vi(N);
		for(int i=0;i<N;i++)
		{
			cin>>vi[i].first;
			vi[i].second=i;
		}
		for(int i=0;i<N;i++)
		{
			cin>>P[i];
			P[i]--;
		}
		sort(vi.begin(),vi.end());
		reverse(vi.begin(),vi.end());
		BIT<int>bit(N);
		for(int i=0;i<N;i++)
		{
			inv[vi[i].second]=i;
			bit.add(i,1);
		}
		long long ans=0;
		int k=0;
		for(int i=1;i<=N;i++)
		{
			if(N-i+1<i)break;
			int t=bit.lower_bound(i);
			if(ans<(long long)i*vi[t-1].first)
			{
				ans=(long long)i*vi[t-1].first;
				k=i;
			}
			bit.add(inv[P[i-1]],-1);
		}
		cout<<ans<<" "<<k<<"\n";
	}
}
