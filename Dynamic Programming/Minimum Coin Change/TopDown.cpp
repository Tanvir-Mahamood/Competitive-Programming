//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

int mincoins(int n,int coins[],int T,int dp[])
{
    if(n==0) return 0; //Base Case
    //Recursion Case

    if(dp[n] != 0) return dp[n];

    int ans=INT_MAX;
    for(int i=0;i<T;i++)
    {
        if(n-coins[i]>=0)
        {
            int subprob=mincoins(n-coins[i],coins,T,dp);
            ans=min(ans,subprob+1);
        }
    }
    dp[n]=ans;
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,T;
    cin>>n>>T;
    int coins[T];
    for(int i=0;i<T;i++) cin>>coins[i];
    int dp[100]={0};
    //int T=sizeof(coins)/sizeof(int);

    cout<<mincoins(n,coins,T,dp)<<nn;

    return 0;
}



