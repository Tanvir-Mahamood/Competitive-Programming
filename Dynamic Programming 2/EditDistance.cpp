//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mod 1000000007

//Top Down Approach
int dp[5001][5001];
int solve(int i,int j,string& s1,string& s2)
{
    if(i==s1.length() || j==s2.length())
    {
        return max(s2.length()-j,s1.length()-i);
    }
    if(dp[i][j] != -1) return dp[i][j];

    int op1,op2,op3; //Add, Remove, Replace
    int ans;

    if(s1[i]==s2[j])
    {
        ans=solve(i+1,j+1,s1,s2);
    }
    else
    {
        op1=1+solve(i,j+1,s1,s2);
        op2=1+solve(i+1,j,s1,s2);
        op3=1+solve(i+1,j+1,s1,s2);
        ans=min(min(op1,op2),op3); //min(op1,op2,op3)
    }

    return dp[i][j]=ans;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp,-1,sizeof dp);
    string str1,str2;
    cin>>str1>>str2;

    cout<<solve(0,0,str1,str2)<<nn;

    return 0;
}



