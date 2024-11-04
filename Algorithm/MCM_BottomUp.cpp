//Matrix Chain Multiplication
//more efficient

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

int MCM(vector<int> &arr, int N)
{
    int dp[N][N];

    for(int i=0; i<N; i++) dp[i][i] = 0;


    for(int i=N-1; i>=1; i--)
    {
        for(int j=i+1; j<N; j++)
        {
            int minn = 1e9;
            for(int k=i; k<j; k++)
            {
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                minn = min(minn, steps);
            }
            dp[i][j] = minn;
        }
    }

    return dp[1][N-1];
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




