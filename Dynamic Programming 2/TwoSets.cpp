//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mod 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,i;
    cin>>n;
    ll dp[n+1][n*n]; //i,sum
    dp[0][0]=1;
    for(i=1; i<(n*n)/2; i++)
    {
        dp[0][i]=0;
    }

    for(i=1; i<=n; i++)
    {
        for(int x=0; x<=((n*(n+1))/4); x++)
        {
            //dp[i][x]=((x<i) ? 0 : dp[i-1][x-i]) + dp[i-1][x];
            dp[i][x]=(((x<i) ? 0 : dp[i-1][x-i]) + dp[i-1][x])%mod;
        }
    }
    if((n*(n+1))%4 != 0) cout<<0;
    //else cout<<(dp[n][(n*(n+1))/4])/2<<nn;
    else cout<<(dp[n][(n*(n+1))/4]*500000004) % mod;

    /*insted of giving output dp/2, we can output Modular Multiplicative Inverse of 2
    Referrence-
    https://planetcalc.com/3311/
    */


    return 0;
}



