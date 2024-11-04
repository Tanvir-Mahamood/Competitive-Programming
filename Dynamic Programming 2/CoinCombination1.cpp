//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mod 1000000007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,i,x;
    cin>>n>>x;
    vector<int> coins(n);
    int dp[x+1];
    dp[0]=1;
    for(i=0;i<n;i++) cin>>coins[i];

    for(i=1;i<=x;i++)
    {
        dp[i]=0;
        for(int con: coins)
        {
            if(con<=i)
                dp[i] = (dp[i] + dp[i-con]) % mod;
        }
    }

    cout<<dp[x]<<nn;


    return 0;
}



