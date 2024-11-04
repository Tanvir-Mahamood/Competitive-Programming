//In the name of Allah, the Gracious, the Merciful
//Time Complexity : O(r * n)
//Using DP Tabulation method ( Iterative approach )
#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

ll factorial(int n)
{
    if(n == 0) return 1;

    if(n < 0) return -1;
    ll res = 1;
    for (int i = 2; i < n + 1; ++i)
        res *= i;
    return res;
}

ll StirlingFirst(int r, int n)
{
    vector<vector<long long> > dp(n + 1, vector<long long>(r + 1, 0));

    for(int i = 0; i <= n; i++) dp[i][i] = 1;

    for(int i = 1; i <= r; i++) dp[1][i] = factorial(i - 1);

    for(int i = 2; i <= n; i++)
    {
        for(int j = 2; j <= r; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + (j - 1) * dp[i][j - 1];
        }
    }
    return dp[n][r];
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, r;
    cin >> n >> r;
    ll ans = StirlingFirst(n, r);

    if(ans == -1) cout << "No Stirling Number\n" ;
    else cout << ans << nn;

    return 0;
}



