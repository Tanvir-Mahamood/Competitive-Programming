/*
Find subsequence or subsets of a given string.
Input: "abc"
Output: " ", a,b,c,ab,bc,ca,abc
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

void filterChars(int n, vector<int> &v)
{
    int j = 0;
    while(n > 0)
    {
        if(n & 1) cout << v[j] << " ";
        j++;
        n = (n >> 1);
    }
    cout << nn;
}

void solve()
{
    int n, i;
    cin >> n;
    vector<int> v(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
    }

    for(i=0; i<(1<<n); i++)
    {
        filterChars(i, v);
    }
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



