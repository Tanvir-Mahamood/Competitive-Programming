#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

#define nn     "\n"
#define ll     long long
#define ull    unsigned long long
#define yes    cout<<"YES\n"
#define no     cout<<"NO\n"
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
#define mod    1000000007
#define PI     3.141592653589793238462

void solve()
{
    ll n, i, cnt = 0;
    cin >> n;
    int a[n], b[n], c[n];
    for(i=0; i<n; i++) cin >> a[i];
    for(i=0; i<n; i++) cin >> b[i];
    for(i=0; i<n; i++) c[i] = a[i] = a[i] - b[i];

    PBDS St;
    for(i=0; i<n; i++)
    {
        cnt += St.size() - St.order_of_key({-c[i], 10000000});
        St.insert({c[i], i});
    }
    cout << cnt << nn;

}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}



