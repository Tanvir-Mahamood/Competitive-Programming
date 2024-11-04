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
    //Iterate over all state 1...N
    for(int i=1;i<=n;i++)
    {
        dp[i]=INT_MAX;
        for(int j=0;j<T;j++)
        {
            if(i-coins[j]>=0)
            {
                int subprob=dp[i-coins[j]];
                dp[i]=min(dp[i],subprob+1);
            }
        }
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,T;
    cin>>T>>n;
    int coins[T];
    for(int i=0;i<T;i++) cin>>coins[i];
    int dp[105]={0};
    //int T=sizeof(coins)/sizeof(int);

    cout<<mincoins(n,coins,T,dp)<<nn;

    return 0;
}




