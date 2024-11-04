/*
Unique number-2
Given an array of n integers. All the integers present twice in the array except for 2 numbers.
They appears once in the array. Determine them.
n < 10^5

Sample Input:
8
5 1 2 1 2 3 5 7
Output:
3 7

Solution:
res = xor all elements
    = 5^1^2^1^2^3^5^7
    = 3^7
    = 4 = 0100 => 2nd bit is set
a = list of numbers having 2nd bit set
  = {5, 5, 7}
  xor operation
a = 5^5^7 = 7
b = res ^ a = 3^7^7 = 3
print(a, b)

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
    int n ,i, res = 0, a = 0, b = 0;
    cin >> n;
    vector<int> v(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
        res = (res ^ v[i]);
    }

    int temp = res;
    int pos = 0;

    while((temp & 1) != 1)
    {
        pos++;
        temp = (temp >> 1);
    }

    int mask = (1 << pos);

    for(i=0; i<n; i++)
    {
        if((v[i] & mask) > 0) a = (a ^ v[i]);
    }
    b = res ^ a;
    (a <= b) ? cout << a << " " << b << nn : cout << b << " " << a << nn;

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



