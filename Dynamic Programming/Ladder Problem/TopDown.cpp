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
    //Base case
    if(n==0) return 1;

    //Recursion Case
    if(dp[n] != 0) return dp[n];

    int ways=0;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
            ways+=ladder(n-i,k,dp);
    }
    return dp[n]=ways;
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



