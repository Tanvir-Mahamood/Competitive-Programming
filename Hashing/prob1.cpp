/*
Divisors of string
*/

#include <bits/stdc++.h>
using namespace std;

#define nn     "\n"
#define ll     long long
#define ull    unsigned long long
#define yes    cout<<"YES\n"
#define no     cout<<"NO\n"
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
//#define mod    1000000007
#define PI     3.141592653589793238462

const int N = 1e6 + 9;
const int p1 = 137, mod1 = 1e9 + 7, p2 = 277, mod2 = 1e9 + 9;

int power(ll n, ll k, int mod)
{
    int ans = 1 % mod; n %= mod; if(n < 0) n += mod;
    while(k)
    {
        if(k & 1) ans = ((ll)ans * n) % mod;
        n = ((ll) n * n) % mod;
        k >>= 1;
    }
    return ans;
}

int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec()
{
    pw[0] = {1, 1};
    for(int i=1; i<N; i++)
    {
        pw[i].first = (1LL * pw[i-1].first * p1) % mod1;
        pw[i].second = (1LL * pw[i-1].second * p2) % mod2;
    }
    ip1 = power(p1, mod1-2, mod1);
    ip2 = power(p2, mod2-2, mod2);
    ipw[0] = {1, 1};
    for(int i=1; i<N; i++)
    {
        ipw[i].first = (1LL * ipw[i-1].first * ip1) % mod1;
        ipw[i].second = (1LL * ipw[i-1].second * ip2) % mod2;
    }
}

pair<int, int> string_hash(string s)
{
    int n = s.size();
    pair<int, int> hs({0, 0});
    for(int i=0; i<n; i++)
    {
        hs.first += (1LL * s[i] * pw[i].first) % mod1;
        hs.first %= mod1;
        hs.second += (1LL * s[i] * pw[i].second) % mod2;
        hs.second %= mod2;
    }
    return hs;
}

pair<int, int> pref[N];
void build(string s)
{
    int n = s.size();
    for(int i=0; i<n; i++)
    {
        pref[i].first = (1LL * s[i] * pw[i].first) % mod1;
        if(i) pref[i].first = (pref[i].first + pref[i-1].first) % mod1;
        pref[i].second = (1LL * s[i] * pw[i].second) % mod2;
        if(i) pref[i].second = (pref[i].second + pref[i-1].second) % mod2;
    }
}

pair<int, int> get_hash(int i, int j)
{
    assert(i <= j);
    pair<int, int> hs({0, 0});

    hs.first = pref[j].first;
    if(i) hs.first = (hs.first - pref[i-1].first + mod1) % mod1;
    hs.first = (1LL * hs.first * ipw[i].first) % mod1;

    hs.second = pref[j].second;
    if(i) hs.second = (hs.second - pref[i-1].second + mod2) % mod2;
    hs.second = (1LL * hs.second * ipw[i].second) % mod2;

    return hs;
}



int main() {
    fastio;
    prec();
    string str; cin >> str;
    build(str);

    int ans = 0, n = str.size(), i, len;

    for(len=1; len<=n/2; len++)
    {
        bool ok = true;
        for(i=0; i+len-1<n; i+=len)
        {
            ok &= (get_hash(i, i+len-1) == get_hash(0, len-1));
        }

        if(ok)
        {
            for(i=0; i<len; i++) cout << str[i];
            cout << nn;
        }
    }

    return 0;
}



