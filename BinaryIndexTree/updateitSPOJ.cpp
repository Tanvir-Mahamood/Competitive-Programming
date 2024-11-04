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

void update(vector<int> &BIT, int i, int inc, int n)
{
    while(i <= n)
    {
        BIT[i] += inc;
        i += (i & (-i));
    }
}
int query(vector<int> &BIT, int i)
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
    int n, q, u, l, r, val, idx;
    cin >> n >> u;
    vector<int> BIT(n+1, 0);

    while(u--)
    {
        cin >> l >> r >> val;
        l++, r++;
        update(BIT, l, val, n);
        update(BIT, r+1, -val, n);
    }
//    for(int i=1; i<=n; i++)
//    {
//        cout << BIT[i] << " ";
//    }
    cin >> q;
    while(q--)
    {
        cin >> idx;
        idx++;
        cout << query(BIT, idx) << nn;
    }
}

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--)
    solve();

    return 0;
}





