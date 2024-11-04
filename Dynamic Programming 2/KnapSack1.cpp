//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007
#define INF (1LL<<62)
#define N 2000006

int w[N], v[N];
ll dp[105][100005];
int n;

ll solve(int indx, int rem)
{
    //if(rem < 0) return -INT_MAX;
    if(indx == n) return 0;

    if(dp[indx][rem] != -1) return dp[indx][rem];

    ll res = -INF;

    res = max(res, solve(indx+1, rem));
    if(rem >= w[indx]) res = max(res, v[indx] + solve(indx+1, rem-w[indx] ));

    return dp[indx][rem] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int  i, W;
    memset(dp,-1,sizeof(dp));
    cin >> n >> W;
    for(i=0; i<n; i++)
    {
        cin >> w[i] >> v[i];
    }

    cout << solve(0, W) << nn;

    return 0;
}



