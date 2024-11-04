//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,x,i,sum,op1,op2;

    cin>>n>>x; //number of coins, summation of money
    vector<int> coins(n+1);
    for(i=1; i<n+1; i++)
    {
        cin>>coins[i];
    }

    int dp[n+1][x+1];

    for(i=1; i<=n; i++)
    {
        for(sum=0; sum<=x; sum++) //coin
        {
            if(sum==0) dp[i][sum]=1;
            else
            {
                op1 = (coins[i]>sum) ? 0 : dp[i][sum-coins[i]];
                op2 = (i==1)         ? 0 : dp[i-1][sum];

                //dp[i][sum]=op1+op2;
                dp[i][sum]=(op1+op2)%mod;
            }
        }
    }
    cout<<dp[n][x]<<nn;

    return 0;
}




