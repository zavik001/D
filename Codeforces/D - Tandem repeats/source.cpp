#include <bits/stdc++.h>
#define ll long long
#define printyes cout<<"YES"<<endl
#define printno cout<<"NO"<<endl
#define endl '\n'
#define M 1000000007
void __print(auto x){
   std::cerr << x;
}
void __print(std::pair<auto,auto> p){
   std::cerr << "{" << p.first <<","<<p.second<<"}";
}
void _print() {std::cerr << "]\n";}
template<typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) std::cerr << ", "; _print(v...);}
#define debug(x...) std::cerr << "[" << #x << "] = ["; _print(x)
template<typename T>
void __print_auto(const T &x) {
   int f = 0;
   std::cerr << '{'; for (auto &i: x) std::cerr << (f++ ? "," : ""), __print(i); std::cerr << "}"<<endl;
}
#define debugmul(v...) std::cerr<< "[" << #v <<"] = ["; __print_auto(v) 
#define precision(x, p) std::cout << std::fixed << std::setprecision(p) << x << std::endl;
#define pb push_back
#define get_bit(x,r) (x&(1<<r))
#define all(v) v.begin(),v.end()
#define sz(x) (int)x.size()
#define srt(v) sort(all(v))
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define pii pair<int,int>
#define hashmap unordered_map<int,int>
using namespace std;

int compare(string &s,int x,int y){
   if(y+y-x>s.length()) return 0;
   for(int i=x;i<y;i++){
      if(s[i]=='?' || s[i+y-x]=='?' || (s[i]==s[i+y-x])) continue;
      else return 0;
   }
   return (y-x)*2;
}

void solve(){
   string s;
   cin>>s;
   int n = s.length();
   vector<int> arr[26];
   for(int i=0;i<n;i++){
      if(s[i]=='?'){
         
      }else{
         arr[s[i]-'a'].pb(i);
      }
   }
   bool allq = true;
   for(int i=0;i<n;i++){
      if(s[i]!='?'){
         allq = false;
      }
   }
   if(allq){
      cout<<n/2*2<<endl;
      return;
   }
   for(int i=0;i<n;i++){
      if(s[i]=='?'){
         for(int j=0;j<26;j++){
               if(arr[j].size()){
                  arr[j].pb(i);
               }
         }
      }
   }
   int ans = 0;
   // if(s=="code?????s")
   // for(int i=0;i<26;i++){
   //     if(arr[i].size())
   //     debugmul(arr[i]);
   // }
   for(int i=0;i<26;i++){
      for(auto &element1:arr[i]){
         for(auto &element2:arr[i]){
               if(element2<=element1) continue;
               if((element2-element1)*2>ans){
                  ans = max(ans,compare(s,element1,element2));
                  // debug(ans);
               }
         }
      }
   }
   // debug();
   cout<<ans<<endl;
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll t=1;
   cin>>t;
   while(t--){
      solve();
   }
   return 0;
}