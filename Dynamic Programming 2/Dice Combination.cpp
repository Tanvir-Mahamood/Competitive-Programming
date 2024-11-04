//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mod 1000000007

ll solve(ll n,vector<ll> dp)
{
    ll i,j;
    for(i=1; i<n+1; i++)
    {
        for(j=1; j<=6; j++) //dices
        {
            if(j>i) break;
            //dp[i]+=dp[i-j];
            dp[i]=(dp[i] + dp[i-j])%mod;
        }
    }
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin>>n;
    vector<ll> dp(n+1,0);
    dp[0]=1;
    cout<<solve(n,dp)<<nn;


    return 0;
}



