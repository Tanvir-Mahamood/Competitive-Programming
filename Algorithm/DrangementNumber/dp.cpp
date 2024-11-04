// DP
//O(n)
#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

ll Derangement(int n) //count derangement numbers
{
    int der[n + 1] = {0};

    der[1] = 0;
    der[2] = 1;

    for(int i = 3; i <= n; ++i)
        der[i] = (i - 1) * (der[i - 1] + der[i - 2]);

    return der[n];
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    ll ans = Derangement(n);
    cout << ans << nn;
    return 0;
}



