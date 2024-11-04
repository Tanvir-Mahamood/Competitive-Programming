#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll ModularInverse(ll a, ll m)
{
    ll quotient, temp1, prevX = 0, currX = 1;

    if(m == 1) return 0;

    while(a > 1)
    {
        quotient = a / m;
        temp1    = m;
        m        = a % m;
        a        = temp1;
        temp1    = prevX;
        prevX    = currX - quotient * prevX;
        currX    = temp1;
    }

    return (currX < 0) ? currX + m : currX;
}

class CRT
{
public:
    ll ans = 0, mod = 1;

    void update(ll congruence, ll primeMod)
    {
        ans = mod * ((congruence - ans) % primeMod * ModularInverse(mod, primeMod) % primeMod) + ans;
        mod *= primeMod;
        ans = (ans < 0) ? ans + mod : ans;
    }
};

int main()
{

    /*

    Solving the following system of congruences
    x = 1 (mod 5)
    x = 2 (mod 6)
    x = 3 (mod 7)

    */

    CRT crt;

    // Update the CRT object with each congruence
    crt.update(1, 5);
    crt.update(2, 6);
    crt.update(3, 7);

    cout << "The solution for x is: " << crt.ans << '\n';

    return 0;
}

