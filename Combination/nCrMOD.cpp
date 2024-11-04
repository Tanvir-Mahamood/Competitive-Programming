//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mod 1000000007
#define N 2000006

//Extended Euclidean Algorithm
/*ll inverseMod(ll a)
{
    ll m0 = mod;
    ll y  = 0;
    ll x  = 1;

    while (a > 1)
    {
        ll q = a / m0;
        ll t = m0;

        m0 = a % m0;
        a  = t;
        t  = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0) x += mod;

    return x;
}*/

//Fermat's Little Theorem
ll powerMod(ll a, ll b)
{
    if(b == 0) return 1;

    if(b%2 == 0)
    {
        ll x = powerMod(a, b/2);
        return (x*x)%mod;
    }
    else
    {
        ll x = powerMod(a, b/2);
        return ((x*x)%mod * a)%mod;
    }

    return 0;
}

ll inverseMod(ll a)
{
    return powerMod(a, mod-2);
}

ll fact[N];

ll nCrMOD(ll n, ll r)
{
    if(r == 0) return 1;
    if(r > n)  return 0;

    ll res = fact[n] * inverseMod( (fact[r] * fact[n-r]) % mod);

    return res % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    for(ll i=1; i<N; i++)
    {
        //fact[i] = (fact[i-1] * i) % mod;
        fact[i] = (fact[i-1] * i) % mod;
    }

    ll n,r;
    cin>>n>>r;

    cout<<nCrMOD(n, r)<<nn;

    return 0;
}



