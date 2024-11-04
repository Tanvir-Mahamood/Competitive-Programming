//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
//Top Down Apporach
//Time Complexity: O(N)
//Space Complexity: O(N)

int fibo(int n,int dp[])
{
    if(n==0 || n==1) return n;

    if(dp[n] != 0) return dp[n];

    int ans;
    ans=fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n]=ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin>>n;
    int dp[100]={0};
    cout<<fibo(n,dp)<<nn;

    return 0;
}



