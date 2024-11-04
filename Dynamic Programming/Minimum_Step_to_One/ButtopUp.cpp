//In the name of Allah, the Gracious, the Merciful

/*Given, N
N=>n/3 ; if(n%3==0)
N=>n/2 ; if(n%2==0)
N=>n-1
Output: Minimum number of operations to make N equal to 1*/

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

int minStep(int n,int dp[])
{
    //Base case
    dp[1]=0;

    for(int i=2;i<=n;i++)
    {
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        if(n%3==0)
        {
            op1=dp[i/3];
        }
        if(n%2==0)
        {
            op2=dp[i/2];
        }
        op3=dp[i-1];

        dp[i]=min(min(op1,op2),op3)+1;
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    int dp[101]={0};
    cout<<minStep(n,dp)<<nn;

    return 0;
}




