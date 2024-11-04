//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mod 1000000007
#define N 1000009
ll expo(ll a, ll b, ll m) { ll res = 1; while(b > 0){ if(b & 1) res = (res * a) % m ;   a = (a * a) % m ;   b = b >> 1;} return res; }

ll fact[N];

//Multiplicative inverse of (a mod m) = a^(m-2) % m
//ans = fact(n) / (fact(i) * (fact(n-i)))
//ans = fact(i) * inverse((fact(i) * (fact(n-i)))
ll nCrMOD(ll n, ll r)
{
    ll ans = fact[n];
    ans = (ans * expo(fact[r],   mod - 2, mod)) % mod;
    ans = (ans * expo(fact[n-r], mod - 2, mod)) % mod;
    return ans;
}

int main()
{
    fact[0] = 1;
    for(ll i=1; i<N; i++)
    {
        fact[i] = (fact[i-1] * i) % mod;
    }

    ll a, b, ans;
    cin >> a >> b;
    ans = nCrMOD(a, b);
    cout << ans << nn;


    return 0;
}

