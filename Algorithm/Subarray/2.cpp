//Number of sub-array having sum divisible by d

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
    ll d, n, i, val, cnt = 0, sum = 0;
    cin >> d >> n;
    map<ll, ll> mp;
    mp[0] = 1;
    for(i=1; i<=n; i++)
    {
        cin >> val;
        sum = (sum + val) % d;
        cnt += mp[sum];
        mp[sum]++;
    }
    cout << cnt << nn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t; cin>>t; while(t--)
    solve();

    return 0;
}



