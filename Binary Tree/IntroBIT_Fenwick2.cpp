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

vector<int> a(10000), BIT(10000);

void update(int i, int inc, int n)
{
    while(i <= n)
    {
        BIT[i] += inc;
        i += (i & (-i));
    }
}
int query(int i)
{
    int ans = 0;
    while(i > 0)
    {
        ans += BIT[i];
        i -= (i & (-i));
    }
    return ans;
}

void solve()
{
    int n, i, q, l, r;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
        update(i, a[i], n);
    }

    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        cout << query(r) - query(l-1) << nn;
    }
}

int main() {
    solve();

    return 0;
}



