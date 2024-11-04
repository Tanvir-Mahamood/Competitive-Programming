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

void update(int i, int val, int n)
{
    while(i <= n)
    {
        BIT[i] = max(BIT[i], val);
        i += (i & (-i));
    }
}
int query(int i)
{
    int ans = 0;
    while(i > 0)
    {
        ans = max(BIT[i], ans);
        i -= (i & (-i));
    }
    return ans;
}

void solve()
{
    int n, i, q, idx;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
        update(i, a[i], n);
    }

    cin >> q;
    while(q--)
    {
        cin >> idx;
        cout << query(idx) << nn;
    }
}

int main() {
    solve();

    return 0;
}




