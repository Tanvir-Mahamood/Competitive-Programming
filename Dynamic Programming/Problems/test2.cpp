//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

int mincoins(int n,vector<int> coins,int T,int dp[])
{
    if(n<0) return 0;
    if(n==0) return 1;
    if(T<=0) return 0;

    if(dp[n] != 0) return dp[n];

    ll ans=0;

    for(int i=0;i<T;i++)
    {
        int subP1=mincoins(n-coins.back(),coins,T,dp);
        coins.pop_back();
        T=coins.size();
        int subP2=mincoins(n,coins,T,dp);

        ans+=(subP1+subP2);
    }
    dp[n]=ans;
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,T,val;
    cin>>n>>T; //sum, no of coins
    vector<int> coins;
    for(int i=0;i<T;i++)
    {
        cin>>val;
        coins.push_back(val);
    }
    int dp[100]={0};
    //int T=sizeof(coins)/sizeof(int);

    cout<<mincoins(n,coins,T,dp)<<nn;

    return 0;
}



