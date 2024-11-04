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

void printBinary(int num)
{
    for(int i=31; i>=0; --i)
    {
        cout << ((num >> i) & 1);
    }
    cout << nn;
}

int DectoBin(int n)
{
    int ans = 0;
    int p = 1;
    while(n > 0)
    {
        ans += (p * (n&1));
        p *= 10;
        n = n>>1;
    }
    return ans;
}

void solve()
{
    printBinary(25);
    cout << DectoBin(25) << nn;;
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}



