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
    if(n==1) return 0;

    //Recursion case

    if(dp[n] != 0) return dp[n]; //Looking if N is already computed

    int op1,op2,op3;
    op1=op2=op3=INT_MAX;

    if(n%3==0)
    {
        op1=minStep(n/3,dp)+1;
    }
    if(n%2==0)
    {
        op2=minStep(n/2,dp)+1;
    }
    op3=minStep(n-1,dp)+1;

    int ans=min(min(op1,op2),op3);
    return dp[n]=ans;;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    int dp[101]={0};
    cout<<minStep(n,dp);

    return 0;
}



