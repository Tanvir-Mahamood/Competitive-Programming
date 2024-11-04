//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

int profit(int wines[],int i,int j,int y,int dp[][100])
{
    if(i>j) return 0;

    if(dp[i][j] != 0) return dp[i][j];

    int op1= wines[i]*y + profit(wines,i+1,j,y+1,dp);
    int op2= wines[j]*y + profit(wines,i,j-1,y+1,dp);
    return dp[i][j]=max(op1,op2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,i;
    cin>>n;
    int wines[n];
    for(i=0;i<n;i++)
    {
        cin>>wines[i];
    }

    int dp[100][100]={0};

    cout<<profit(wines,0,n-1,1,dp)<<nn;

    return 0;
}



