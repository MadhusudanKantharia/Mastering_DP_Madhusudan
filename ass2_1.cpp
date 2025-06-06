#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vin(V,n) for(ll i=0;i<n;i++){V.push_back(0);cin>>V[i];}
#define vout(V) for(auto &e:V){cout<<e<<" ";}cout<<endl;
#define INF 1e18
#define all(X) X.begin(),X.end()

ll recurse(vll &dp,ll N){
    // cout<<N<<"\t";
    if(dp[N]!=-1)return dp[N];
    if(N%2==0){
        // cout<<1<<" ";
        return dp[N]=(recurse(dp,N/2)+1);
    }
    else{
        // cout<<0<<" ";
        return dp[N]=min(recurse(dp,N-1),recurse(dp,N+1))+1;
    }
}
void solve(){
    
    ll N;
    cin>>N;
    vll dp(N+2,-1);
    dp[1]=0;
    cout<<recurse(dp,N)<<endl;
    // vout(dp);
}

int main() {
    ll t=1;
    // cin >> t;
    while(t--) solve();
}