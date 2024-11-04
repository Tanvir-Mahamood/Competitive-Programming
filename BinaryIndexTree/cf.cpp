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

ll BIT[1000005], pre_cnt[1000005], suf_cnt[1000005], lft[1000005], rgt[1000005], arr[1000005];

void update(ll i, ll inc, ll n)
{
    while(i <= n)
    {
        BIT[i] += inc;
        i += (i & (-i));
    }
}
ll query(ll i)
{
    ll ans = 0;
    while(i > 0)
    {
        ans += BIT[i];
        i -= (i & (-i));
    }
    return ans;
}


void solve()
{
    ll n, i, ans = 0;
    cin >> n;
    for(i=0; i<n; i++) cin >> arr[i];
    for(i=0; i<n; i++)
    {
        pre_cnt[arr[i]]++;
        lft[i] = pre_cnt[arr[i]];
    }
    for(i=n-1; i>=0; i--)
    {
        suf_cnt[arr[i]]++;
        rgt[i] = suf_cnt[arr[i]];
    }
//    for(i=0; i<n; i++) cout << lft[i] << " "; cout << nn;
//    for(i=0; i<n; i++) cout << rgt[i] << " "; cout << nn;

    for(i=0; i<n; i++)
    {
        ans += (i - query(rgt[i]));
        update(lft[i], 1, n);
    }

//    for(i=n-1; i>=0; i--)
//    {
//        ans += query(rgt[i]);
//        update(lft[i], 1, n);
//    }

    cout << ans << nn;
}

int main() {
    fastio;
    ll t = 1;
    //cin >> t;
    for(ll i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}



