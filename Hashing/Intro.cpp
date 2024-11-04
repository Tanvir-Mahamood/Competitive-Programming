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

const int p1 = 137, mod1 = 1e9 + 7;
const int p2 = 277, mod2 = 1e9 + 9;
const int N = 1e5 + 9;
int pw1[N], pw2[N];

void prec()
{
    pw1[0] = 1;
    for(int i=1; i<=N; i++)
    {
        pw1[i] = 1ll * pw1[i-1] * p1 % mod1;
    }

    pw2[0] = 1;
    for(int i=1; i<=N; i++)
    {
        pw2[i] = 1ll * pw2[i-1] * p2 % mod2;
    }
}

pair<int, int> get_hash(string s)
{
    int n = s.size();

    int hs1 = 0;
    for(int i=0; i<n; i++)
    {
        hs1 += 1ll * s[i] * pw1[i] % mod1;
        hs1 %= mod1;
    }

    int hs2 = 0;
    for(int i=0; i<n; i++)
    {
        hs2 += 1ll * s[i] * pw2[i] % mod2;
        hs2 %= mod2;
    }

    return {hs1, hs2};
}

void solve()
{
    string a, b;
    cin >> a >> b;

    if(get_hash(a) == get_hash(b)) cout << "same\n";
    else cout << "not same\n";
}

int32_t main() {
    fastio;
    int t = 1;
    prec();
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}









//#include <bits/stdc++.h>
//using namespace std;
//
//#define nn     "\n"
//#define ll     long long
//#define ull    unsigned long long
//#define yes    cout<<"YES\n"
//#define no     cout<<"NO\n"
//#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
//#define mod    1000000007
//#define PI     3.141592653589793238462
//
//const int p1 = 137, mod1 = 1e9 + 7;
//const int p2 = 277, mod2 = 1e9 + 9;
//const int N = 1e5 + 9;
//
//pair<int, int> pw[N], ipw[N];
//
//int power(ll a, ll b, ll m)
//{
//    ll res = 1;
//    while(b > 0)
//    {
//        if(b & 1) res = (res * a) % m ;
//        a = (a * a) % m ;
//        b = b >> 1;
//    }
//    return res;
//}
//
//void prec()
//{
//    pw[0] = {1, 1};
//    for(int i=1; i<N; i++)
//    {
//        pw[i].first = 1ll * pw[i-1].first * p1 % mod1;
//        pw[i].second = 1ll * pw[i-1].second * p2 % mod2;
//    }
//    int ip1 = power(p1, mod1-2, mod1);
//    int ip2 = power(p2, mod2-2, mod2);
//
//    ipw[0] = {1, 1};
//    for(int i=1; i<N; i++)
//    {
//        ipw[i].first = 1ll * ipw[i-1].first * ip1 % mod1;
//        ipw[i].second = 1ll * ipw[i-1].second * ip2 % mod2;
//    }
//}
//
//pair<int, int> get_hash(string s)
//{
//    int n = s.size();
//
//    pair<int, int> hs({0, 0});
//    for(int i=0; i<n; i++)
//    {
//        hs.first += 1ll * s[i] * pw[i].first % mod1; hs.first %= mod1;
//        hs.second += 1ll * s[i] * pw[i].second % mod2; hs.second %= mod2;
//    }
//    return hs;
//}
//
//void solve()
//{
//    string a, b;
//    cin >> a >> b;
//
//    if(get_hash(a) == get_hash(b)) cout << "same\n";
//    else cout << "not same\n";
//}
//
//int32_t main()
//{
//    fastio;
//    int t = 1;
//    prec();
//    //cin >> t;
//    for(int i=1; i<=t; i++)
//    {
//        //cout << "Case " << i << ": \n";
//        solve();
//    }
//
//    return 0;
//}




