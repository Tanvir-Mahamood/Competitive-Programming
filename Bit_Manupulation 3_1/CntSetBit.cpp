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

int CountSetBit_1(int n) // O(lgn)
{
    int cnt = 0;
    while(n > 0)
    {
        cnt += (n & 1);
        n = n >> 1;
    }
    return cnt;
}

int CountSetBit_2(int n) // fast, O(no. of set bits)
{
    int cnt = 0;
    while(n > 0)
    {
        n = n & (n - 1); // remove last set bit
        cnt++;
    }
    return cnt;
}


void solve()
{
    int n;
    cin >> n;
    cout << CountSetBit_1(n) << nn;
    cout << CountSetBit_2(n) << nn; // in worse case, it is same as first method
    cout << __builtin_popcount(n) << nn;
}

int main() {
    //fastio;
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}



