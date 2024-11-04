//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

ll power(ll a, ll n)
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

int main() {
    cout << power(2,50) << nn;

    return 0;
}



