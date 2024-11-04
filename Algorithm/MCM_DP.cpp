//Matrix Chain Multiplication

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int minn = 1e9;
    for(int k=i; k<j; k++)
    {
        int steps = arr[i-1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        minn = min(minn, steps);
    }
    return dp[i][j] = minn;
}

int MCM(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f(1, N-1, arr, dp);
}


int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int n, i;
    cin >> n;
    vector<int> v(n);
    for(i=0; i<n; i++) cin >> v[i];
    int res = MCM(v, n);
    cout << res << nn;


    return 0;
}



