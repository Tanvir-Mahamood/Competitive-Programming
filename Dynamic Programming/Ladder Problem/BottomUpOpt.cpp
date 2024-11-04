//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

int ladderOptimised(int n,int k,int dp[])
{
    dp[0]=dp[1]=1;
    for(int i=2;i<=k;i++)
    {
        dp[i]=2*dp[i-1];
    }
    for(int i=k+1;i<=n;i++)
    {
        dp[i]=2*dp[i-1]-dp[i-k-1];
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    int dp[100]={0};
    cin>>n>>k;  //Number of steps and number of jumps
    cout<<ladderOptimised(n,k,dp)<<nn;

    return 0;
}






