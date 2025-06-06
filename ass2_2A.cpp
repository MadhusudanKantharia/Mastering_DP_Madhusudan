#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vin(V,n) for(ll i=0;i<n;i++){V.push_back(0);cin>>V[i];}
#define vout(V) for(auto &e:V){cout<<e<<" ";}cout<<endl;
#define INF 1e18
#define all(X) X.begin(),X.end()

vll s(1e5+10);


void solve(){
    ll n;
    cin>>n;
    vll p,q;
    vin(p,n);
    vin(q,n);
    vll r(n);
    ll max_p=0,max_q=0;
    for(ll i=0;i<n;i++){
        if(p[max_p]<p[i])max_p=i;
        if(q[max_q]<q[i])max_q=i;
        if(p[max_p]>q[max_q]){
            r[i]=(s[p[max_p]]+s[q[i-max_p]])%998244353;
        }
        else{
            r[i]=(s[p[i-max_q]]+s[q[max_q]])%998244353;
        }
    }
    vout(r);
}

int main() {
    s[0]=1;
    for(ll i=1;i<1e5+10;i++){s[i]=(s[i-1]*2)%998244353;}
    ll t;
    cin >> t;
    while(t--) solve();
}