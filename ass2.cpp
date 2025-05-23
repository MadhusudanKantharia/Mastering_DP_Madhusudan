#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vll vector<long long>
#define vin(V,n) for(ll i=0;i<n;i++){V.push_back(0);cin>>V[i];}
#define vout(V) for(auto &e:V){cout<<e<<" ";}cout<<endl;

ll recurse(vector<vll> &dp,vll &echo,ll n,ll big,map<ll,ll> &bigs){
    if(n==0)return 0;
    if(dp[n][bigs[big]]!=-1)return dp[n][bigs[big]];
    ll pick=0;
    if(echo[n-1]<big)pick=1+recurse(dp,echo,n-1,echo[n-1],bigs);

    ll not_pick=recurse(dp,echo,n-1,big,bigs);
    return dp[n][bigs[big]]=max(pick,not_pick);
}

int main(){
    map<ll,ll> bigs;
    ll n;
    cin>>n;
    vll echo;
    vin(echo,n);
    // vin(echo,n);
    for(ll i=0;i<n;i++){
        bigs.insert({echo[i],i});
    }
    bigs.insert({1e10,n});
    // for(auto e:bigs)cout<<e.first<<" "<<e.second<<endl;
    vector<vll> dp(n+1,vll (n+1,-1));
    cout<<recurse(dp,echo,n,1e10,bigs)<<endl;

    // vout(dp);
}
