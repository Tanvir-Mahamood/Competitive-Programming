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

int CheckBit(int n, int i)
{
    return (n & (1 << i)) ? 1 : 0;
}
int SetBit(int n, int i)
{
    return (n | (1 << i));
}
int ClearBit(int n, int i)
{
    return (n & ~(1 << i));
}
int UpdateBit(int n, int i, int v)
{
    int mask = ~(1 << i);
    int cleared_n = (n & mask);
    return (cleared_n | (v << i));
}
int ClearLastiBits(int n, int i)
{
    return (n & (-1 << i));
}
int ClearRangeBitiToJ(int n, int i, int j)
{
    int a = (~0) << (j + 1);
    int b = (1 <<i) - 1;
    int mask = (a | b);
    return (n & mask);
}

void solve()
{
    int n, i, j, v;
    cout << CheckBit(43,6) << nn;
    cout << SetBit(43,2) << nn;
    cout << ClearBit(43,2) << nn;
    cout << UpdateBit(16,2,1) << nn;
    cout << ClearLastiBits(15,2) << nn;
    cout << ClearRangeBitiToJ(31,1,3) << nn;
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



