/*
count every pair of llegers
for (i<j), (a[i]>a[j])
*/

// Range Sum Query

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

void update(vector<ll> &BIT, ll i, ll inc, ll n)
{
    while(i <= n)
    {
        BIT[i] += inc;
        i += (i & (-i));
    }
}
ll query(vector<ll> &BIT, ll i)
{
    ll ans = 0;
    while(i > 0)
    {
        ans += BIT[i];
        i -= (i & (-i));
    }
    return ans;
}

void convert(vector<ll> &a, ll n)
{
    vector<ll> temp(n+1);
    temp = a;
    sort(temp.begin(), temp.end());
    for(ll i=1; i<=n; i++)
    {
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
    }
}

void solve()
{
    ll n, i, ans = 0, j;
    cin >> n;
    vector<ll> a(n+1, 0), BIT(n+1, 0);
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    convert(a, n);

    for(i=n; i>=1; i--)
    {
        ans += query(BIT, a[i] - 1);
        update(BIT, a[i], 1, n);

        //cout << ans << "  ";
        //for(j=1; j<=n; j++) cout << BIT[j] << " ";
        //cout << nn;
    }
    cout << ans << nn;
}

int main() {
    fastio;
    ll t;
    cin >> t;
    while(t--)
    solve();

    return 0;
}







