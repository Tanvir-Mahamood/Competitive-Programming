//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
//Buttop Up Apporach
//Time Complexity: O(N)

//Space Complexity: O(N)
/*int fibo(int n,int dp[])
{
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}*/

//Space Complexity: O(1)
//Space Optimized
int fibo(int n)
{
    int a,b,c;
    a=0;
    b=1;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //int dp[100]={0};
    int n; cin>>n;
    cout<<fibo(n)<<nn;

    return 0;
}



