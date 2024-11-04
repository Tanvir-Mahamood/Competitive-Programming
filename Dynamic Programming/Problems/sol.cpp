/*
Problem Name: Tilling Problem - II

Problem Constraints: 1 <= T<= 1000 <br>
1 <= N,M <= 100000
Problem Description:
Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m. A tile can either be placed horizontally or vertically.

Input Format: First line of input contains an integer T denoting the number of test cases. Then T test cases follow.The first line of each test case contains two integers N and M.

Sample Input:
2
2 3
4 4
Output Format: Print answer for every test case in a new line modulo 10^9+7.
Sample Output:
1
2
*/


#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7 ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long t,n,m,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<long long> dp(n+1,0);

        dp[0]=1;
        for(i=1; i<=n; i++)
        {
            dp[i]=dp[i-1];

            if((i-m)>=0) dp[i]+=dp[i-m];
            else dp[i]+=0;

            dp[i]%=mod;
        }
        cout<<dp[n]<<"\n";
    }
}

