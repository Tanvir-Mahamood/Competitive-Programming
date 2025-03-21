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
    if(n == 1 or n == 2) return n - 1;

    int a = 0, b = 1;

    for(int i = 3; i <= n; ++i)
    {
        int cur = (i - 1) * (a + b);
        a = b;
        b = cur;
    }

    return b;
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




