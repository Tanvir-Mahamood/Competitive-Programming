//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

int ladder(int n,int k,int dp[])
{
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
                dp[i]+=dp[i-j];
        }
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    int dp[100]={0};
    cin>>n>>k;  //Number of steps and number of jumps
    cout<<ladder(n,k,dp)<<nn;

    return 0;
}





