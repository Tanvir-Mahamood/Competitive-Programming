// https://www.spoj.com/problems/ADACLEAN/
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

const int p1 = 137, mod1 = 1e9 + 7;
const int p2 = 277, mod2 = 1e9 + 9;
const int N = 1e5 + 9;

pair<int, int> pw[N], ipw[N];

int power(ll a, ll b, ll m)
{
    ll res = 1;
    while(b > 0)
    {
        if(b & 1) res = (res * a) % m ;
        a = (a * a) % m ;
        b = b >> 1;
    }
    return res;
}

void prec()
{
    pw[0] = {1, 1};
    for(int i=1; i<N; i++)
    {
        pw[i].first = 1ll * pw[i-1].first * p1 % mod1;
        pw[i].second = 1ll * pw[i-1].second * p2 % mod2;
    }
    int ip1 = power(p1, mod1-2, mod1);
    int ip2 = power(p2, mod2-2, mod2);

    ipw[0] = {1, 1};
    for(int i=1; i<N; i++)
    {
        ipw[i].first = 1ll * ipw[i-1].first * ip1 % mod1;
        ipw[i].second = 1ll * ipw[i-1].second * ip2 % mod2;
    }
}

pair<int, int> string_hash(string s)
{
    int n = s.size();

    pair<int, int> hs({0, 0});
    for(int i=0; i<n; i++)
    {
        hs.first += 1ll * s[i] * pw[i].first % mod1; hs.first %= mod1;
        hs.second += 1ll * s[i] * pw[i].second % mod2; hs.second %= mod2;
    }
    return hs;
}

pair<int, int> pref[N];
void build(string s)
{
    int n = s.size();
    for(int i=0; i<n; i++)
    {
        pref[i].first = 1ll * s[i] * pw[i].first % mod1;
        if(i) pref[i].first = (pref[i].first + pref[i-1].first) % mod1;

        pref[i].second = 1ll * s[i] * pw[i].second % mod2;
        if(i) pref[i].second = (pref[i].second + pref[i-1].second) % mod2;
    }
}

pair<int, int> get_hash(int i, int j)
{
    assert(i <= j);

    pair<int, int> hs({0, 0});

    hs.first = pref[j].first;
    if(i) hs.first = (hs.first - pref[i-1].first + mod1) % mod1;
    hs.first = 1ll * hs.first * ipw[i].first % mod1;

    hs.second = pref[j].second;
    if(i) hs.second = (hs.second - pref[i-1].second + mod2) % mod2;
    hs.second = 1ll * hs.second * ipw[i].second % mod2;

    return hs;
}

struct pair_hash {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        return std::hash<T1>()(p.first) ^ (std::hash<T2>()(p.second) << 1);
    }
};

void solve()
{
    int n, k, i;
    cin >> n >> k;
    string str;
    cin >> str;

    build(str);
    unordered_set<pair<int, int>, pair_hash> mySet;
    for(int i=0; i<=n-k; i++) {
         pair<int, int> ans1 = get_hash(i,i+k-1);
         //cout << ans1.first << " " << ans1.second << nn;
         mySet.insert({ans1.first, ans1.second});
    }
    cout << mySet.size() << nn;
}

int32_t main()
{
    fastio;
    int t = 1;
    prec();
    cin >> t;
    for(int i=1; i<=t; i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}




