//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,i,temp,di,minStep;
    cin>>n;
    vector<int> dp(n+1);
    dp[0]=0;

    for(i=1;i<=n;i++)
    {
        temp=i;
        minStep=INT_MAX;
        while(temp != 0)
        {
            di=temp%10;
            temp/=10;
            if(di==0) continue;
            minStep=min(minStep,1+dp[i-di]);
        }
        dp[i]=minStep;
        //cout<<minStep<<" ";
    }
    cout<<dp[n]<<nn;

    return 0;
}



