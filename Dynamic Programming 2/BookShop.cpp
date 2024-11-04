//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,i,j,x,money,op1,op2;
    cin>>n>>x;

    vector<int> price(n+1);
    vector<int> pages(n+1);

    for(i=1; i<=n; i++) cin>>price[i];
    for(i=1; i<=n; i++) cin>>pages[i];

    int dp[n+1][x+1];

    for(i=0; i<=n; i++) //i starts with 0
    {
        for(money=0; money<=x; money++)
        {
            if(money==0 || i==0) dp[i][money]=0;
            else
            {
                op1 = (i==1)             ? 0 : dp[i-1][money];
                op2 = (money < price[i]) ? 0 : pages[i] + dp[i-1][money-price[i]];

                dp[i][money]=max(op1,op2);
            }
        }
    }
    cout<<dp[n][x]<<nn;

    return 0;
}



