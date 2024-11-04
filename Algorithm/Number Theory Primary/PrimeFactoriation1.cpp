#include <bits/stdc++.h>
using namespace std;

#define nn   "\n"
#define ll   long long
#define ull  unsigned long long
#define yes  cout<<"YES\n"
#define no   cout<<"NO\n"
#define mod  1000000007
#define PI   3.141592653589793238462

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, i;
    cin >> n;

    while(n % 2 == 0)
    {
        cout << 2 << " ";
        n /= 2;
    }
    for(i=3; i<=sqrt(n); i+=2)
    {
        while(n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }
    if(n > 2) cout << n << " ";

    return 0;
}


