#include <bits/stdc++.h>
using namespace std;
#define nn   "\n"
#define ll   long long

ll phi(ll n)
{
    ll result = n;
    for(ll p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }

    if (n > 1) result -= result / n;

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ans = phi(n);
    cout << ans << nn;

    return 0;
}

