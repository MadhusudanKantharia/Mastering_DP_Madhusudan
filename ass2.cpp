#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vll vector<long long>
#define vin(V,n) for(ll i=0;i<n;i++){V.push_back(0);cin>>V[i];}
#define vout(V) for(auto &e:V){cout<<e<<" ";}cout<<endl;

ll recurse(vll &dp,vll &echo,ll n,ll big){
    if(n==0)return 0;
    ll pick=-1;
    if(echo[n-1]<big)pick=1+recurse(dp,echo,n-1,echo[n-1]);
    ll not_pick=recurse(dp,echo,n-1,big);
    return dp[n-1]=max(pick,not_pick);
}

int main(){
    ll n;
    cin>>n;
    vll echo;
    vin(echo,n);
    vll dp(n,-1);
    recurse(dp,echo,n,1e13);
    ll maxx=0;
    for(ll i=0;i<dp.size();i++)maxx=max(dp[i],maxx);
    cout<<maxx<<endl;
    // vout(dp);
}