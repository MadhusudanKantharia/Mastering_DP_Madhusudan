#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define vll vector<long long>
#define vin(V,n) for(ll i=0;i<n;i++){V.push_back(0);cin>>v[i];}
#define vout(V) for(auto &e:V){cout<<e<<" ";}cout<<endl;
struct product{
    ll K;
    ll C;
    ll S;
};
struct log{
    string type;
    string product_ID;
    ll change;
};
struct account{
    ll money;
    ll loan;
};
void Print_products(unordered_map<string,product> &ID){
    for(auto &e:ID){
        cout<<e.first<<" "<<(ID[e.first]).K<<" "<<(ID[e.first]).C<<" "<<(ID[e.first]).S<<endl;
    }
}


ll knapsack(ll n,ll W,vll val,vector<string> wt,vector<vll> &dp, unordered_map<string,product> &ID){
    if(n==0||W==0)return 0;
    if(dp[n][W]!=-1)return dp[n][W];

    ll picked=-1;
    if(ID[wt[n-1]].S<=W)picked=val[n-1]+knapsack(n-1, W-ID[wt[n-1]].S, val, wt, dp, ID);

    ll not_picked=knapsack(n-1, W, val, wt, dp, ID);

    dp[n][W]=max(picked,not_picked);
    return dp[n][W];
}



void update(unordered_map<string,product> &ID,vector<string> &bill,account &store_account,vector<struct log> &transactions){
    for(ll i=0;i<bill.size();i++){
        if(ID[bill[i]].K<1){
            if(store_account.money<ID[bill[i]].C){
                transactions.push_back({"LOAN","NA",ID[bill[i]].C-store_account.money});
                store_account.loan+=ID[bill[i]].C-store_account.money;
                store_account.money+=ID[bill[i]].C-store_account.money;
            }
            transactions.push_back({"RESTOCK",bill[i],-ID[bill[i]].C});
            store_account.money-=ID[bill[i]].C;
            ID[bill[i]].K++;
        }
        transactions.push_back({"PURCHASE",bill[i],ID[bill[i]].S});
        ID[bill[i]].K--;
    }
    for(ll i=0;i<bill.size();i++){
        store_account.money+= ID[bill[i]].S;
    }
}



void solve(unordered_map<string,product> &ID,vector<struct log> &transactions,account &store_account){
    ll B;
    ll m;
    vector<string> cost;
    vll profit;
    string str;
    ll payoff;
    cin>>B>>m;
    for(ll i=0;i<m;i++){
        cin>>str>>payoff;
        cost.push_back(str);
        profit.push_back(payoff);
    }
    vector<vll> dp(m+1,vll (B+1,-1));

    // taking all the inputs above jo bhi hai budget wagera and whatever are the payoff values

    ll total_payoff=knapsack(m, B, profit, cost, dp,ID); //knapsack se solve kar liya what will be the payoff value for the customer


    vector<string> bill;
    ll temp=B;
    for(ll i=m;i>0;i--){
        if(temp-ID[cost[i-1]].S>=0&&dp[i-1][temp-ID[cost[i-1]].S]+profit[i-1]>dp[i-1][temp]){
            // ID[cost[i-1]].K--;
            bill.push_back(cost[i-1]);
            // cout<<cost[i-1]<<" ";
            temp-=ID[cost[i-1]].S;
        }
    }

    // backtracking karke dekh liya what was the list of items which were bought by the customer
    
    update(ID,bill,store_account,transactions);
    
    //har customer ke billing ke baad update kar dena............
}


void print_transactions(vector<struct log> &transactions){
    cout<<"TRANSACTIONS TODAY"<<endl;
    for(ll i=0;i<transactions.size();i++){
        cout<<transactions[i].type;
        for(ll j=0;j<15-transactions[i].type.size();j++)cout<<" ";
        cout<<transactions[i].product_ID;
        for(ll j=0;j<10-transactions[i].product_ID.size();j++)cout<<" ";
        cout<<transactions[i].change<<endl;
    }
}

int main(){
    vector<struct log> transactions;
    unordered_map<string,product> ID;
    account store_account;
    store_account.loan=0;
    store_account.money=0;
    ll P,N;
    cin>>P>>N;
    string str;
    ll k,c,s;
    for(ll i=0;i<P;i++){
        cin>>str>>k>>c>>s;
        ID.insert({str,{k,c,s}});
    }
    // Print_products(ID);
    for(ll i=0;i<N;i++)solve(ID,transactions,store_account);
    // Print_products(ID);
    // transactions.push_back({"REPAY","NA",store_account.loan});
    print_transactions(transactions);
    cout<<"REPAY          "<<"NA        "<<1.1*store_account.loan<<endl;
    cout<<"TOTAL NET INCOME FOR TODAY IS "<<store_account.money-store_account.loan*1.1<<endl;
}