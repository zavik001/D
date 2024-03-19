#include<iostream>//https://codeforces.com/contest/1945/problem/E
#include<cassert>
using namespace std;
int N,X,P[2<<17];
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int T;cin>>T;
   for(;T--;)
   {
      cin>>N>>X;
      int invX;
      for(int i=1;i<=N;i++)
      {
         cin>>P[i];
         if(P[i]==X)invX=i;
      }
      int l=1,r=N+1;
      while(r-l>1)
      {
         int m=(l+r)/2;
         if(P[m]<=X)l=m;
         else r=m;
      }
      if(invX==l)cout<<"0\n";
      else cout<<"1\n"<<invX<<" "<<l<<"\n";
   }
}