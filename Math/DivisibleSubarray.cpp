/*
Given an array of N elements. Compute number of sub arrays divisible by N.
*/

#include <bits/stdc++.h>
using namespace std;

#define nn     "\n"
#define ll     long long
#define ull    unsigned long long
#define yes    cout<<"YES\n"
#define no     cout<<"NO\n"
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
#define mod    1000000007
#define PI     3.141592653589793238462

ll a[1000005], pre[1000005];

void solve()
{
    memset(pre, 0, sizeof(pre));
    pre[0] = 1;

    int n, i, sum = 0;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a[i];
        sum = (sum + a[i]) % n;
        sum = (sum + n) % n;
        pre[sum]++; // bucket ready
    }

    ll ans = 0;
    for(i=0; i<n; i++)
    {
        ans += (pre[i] * (pre[i] - 1) / 2); // nC2
    }
    cout << ans << nn;
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}



