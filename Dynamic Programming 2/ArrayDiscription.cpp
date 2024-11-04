//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mod 1000000007

int solve(int n,int m,vector<int> v)
{
    int ans;
    int dp[n+2][m+2];
    memset(dp,0,sizeof dp);

    for(int i=1; i<=n; i++)
    {
        for(int x=1; x<=m; x++)
        {
            if(i==1)
            {
                if(v[i]==0 || v[i]==x) dp[i][x]=1;
                else dp[i][x]=0;
            }
            else
            {
                if(v[i]==0 || v[i]==x)
                {
                    //dp[i][x]=dp[i-1][x-1]+dp[i-1][x]+dp[i-1][x+1];
                    dp[i][x]=((dp[i-1][x-1]+dp[i-1][x])%mod +dp[i-1][x+1])%mod;
                }
                else dp[i][x]=0;
            }
        }
    }

    ans=0;
    for(int x=1; x<=m; x++) //x is the last element of the array
    {
        //ans=(ans+dp[n][x])
        ans=(ans+dp[n][x])%mod;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)

    int n,m,i;
    cin>>n>>m;
    vector<int> v(n+1);
    for(i=1; i<=n; i++) cin>>v[i];

    cout<<solve(n,m,v)<<nn;

    return 0;
}



