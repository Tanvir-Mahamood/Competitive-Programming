/*
Problem 1:
Given two 32 bits numbers, N and M and two bit position, i and j.
Write a method to set all the bits from i to j in N equal to M.
Sample test case:
Input:
N = 10000000000;
M = 10101, i = 2, j = 6;
Output:
1000 10101 00 (without space)

*/

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

int Problem1(int N, int M, int i, int j)
{
    int n = ClearRangeBitiToJ(N, i, j);
    return (n | (M << i));
}

void solve()
{
    int N, M, i, j;
    cin >> N >> M >> i >> j;
    cout << Problem1(N, M, i, j) << nn;
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



