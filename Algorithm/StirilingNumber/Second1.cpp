//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

ll stirlingSecond(int n, int m)
{
    ll s[n+1][m+1];
    memset(s, 0, sizeof(s[0][0])*(n+1)*(m+1));
    s[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            s[i][j] = j*s[i-1][j] + s[i-1][j-1];
        }
    }
    return s[n][m];
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, r;
    cin >> n >> r;
    ll ans = stirlingSecond(n, r);
    cout << ans << nn;

    return 0;
}



