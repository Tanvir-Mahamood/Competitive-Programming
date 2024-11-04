//Count the number of set bits

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

void solve()
{
    int n; cin >> n;
    int ans1 = __builtin_popcount(n); cout << ans1 << nn;

    ll m; cin >> m;
    int ans2 = __builtin_popcountll(m); cout << ans2 << nn;
}

int main() {
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}



