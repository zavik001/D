//https://codeforces.com/contest/1945/problem/G
#include<iostream>
#include<queue>
#include<cassert>
using namespace std;
int N,D;
int K[2<<17],S[2<<17];
int RK[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>D;
		for(int i=0;i<N;i++)cin>>K[i]>>S[i];
		RK[N]=0;
		for(int i=N;i--;)RK[i]=max(RK[i+1],K[i]);
		priority_queue<pair<pair<int,int>,int> >Q;//((-time,-S),idx)
		priority_queue<pair<pair<int,int>,int> >QK;//((K,-number),idx)
		int number=0;
		int ans=-1;
		int l=0;
		for(int t=1;t<=D;t++)
		{
			assert(l<N);
			if(QK.empty()||RK[l]>=QK.top().first.first)
			{
				Q.push(make_pair(make_pair(-(t+S[l]),-S[l]),l));
				l++;
				if(l==N)
				{
					ans=t;
					break;
				}
			}
			else
			{
				int idx=QK.top().second;
				QK.pop();
				Q.push(make_pair(make_pair(-(t+S[idx]),-S[idx]),idx));
			}
			while(!Q.empty()&&-Q.top().first.first==t)
			{
				int idx=Q.top().second;
				Q.pop();
				QK.push(make_pair(make_pair(K[idx],--number),idx));
			}
		}
		cout<<ans<<"\n";
	}
}
