/*
Fibonacci Series | Some Use cases & Interesting properties
f(n) = f(n-1) + f(n-2)
Sample Problem:

(Q1) Find the number of boolean strings of length N, with no consecutive one's.
(Q2) Find number of ways to build a wall of size 2 X N, with bricks of size 1 X 2 and 2 X 1

How to compute:
- Recursion --------------------------------------O(2^N)
- Top-Down DP ------------------------------------O(N)
- Bottom-Up DP -----------------------------------O(N)
- DP with space optimization (Three variables) ---O(N)
- Matrix Exponentiation --------------------------O(k^3 * logN) = O(logN) , k = 2
- Binet's Formula --------------------------------O(1) , Approximation, works for small value of N
- Codeforces hack --------------------------------O(N)

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

void solve()
{

}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}



