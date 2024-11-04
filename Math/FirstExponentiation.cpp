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

ll power1(ll a, ll n) // using bitmasking
{
    ll ans = 1;
    while(n > 0)
    {
        if(n & 1) ans *= a;
        a *= a;
        n = n >> 1;
    }
    return ans;
}

ll power2(ll a, ll n) // using recursion
{
    if(n == 0) return 1;
    ll subproblem = power2(a, n/2);
    if(n & 1) return (a * subproblem * subproblem);
    return (subproblem * subproblem);
}

int main() {
    ll a, n;
    cin >> a >> n;
    cout << power1(a, n) << nn;
    cout << power2(a, n) << nn;

    return 0;
}



