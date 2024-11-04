//In the name of Allah, the Gracious, the Merciful
//Time Complexity : O(r * n)
#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

ll factorial(int n)
{
    if(n == 0) return 1;

    if(n < 0) return -1;
    ll res = 1;
    for (int i = 2; i < n + 1; ++i)
        res *= i;
    return res;
}

ll nCr(int n, int r)
{
    if(r > n) return -1;
    if(n == r || r == 0) return 1;

    // nCr(n, r) = nCr(n - 1, r - 1) + nCr(n - 1, r)
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

ll StirlingFirst(int n, int r)
{
    if(r > n) return -1;
    if(r == 0) return 0;
    if(r == n) return 1;
    if(r == 1) return factorial(n - 1);
    if(n - r == 1) return nCr(n, 2);
    else return StirlingFirst(n - 1, r - 1) + (n - 1) * StirlingFirst(n - 1, r);
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, r;
    cin >> n >> r;
    ll ans = StirlingFirst(n, r);

    if(ans == -1) cout << "No Stirling Number\n" ;
    else cout << ans << nn;

    return 0;
}



