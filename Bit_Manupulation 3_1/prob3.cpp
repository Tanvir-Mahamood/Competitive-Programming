/*
Given an array of n numbers. All numbers present trice except for one number, which is only present once.
Determine it.
Sample Input:
7
1 1 1 2 2 2 3
Output:
3
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
    int n, i, j, val;
    cin >> n;
    vector<int> cnt(64,0);
    for(i=0; i<n; i++)
    {
        cin >> val;
        j = 0;
        while(val > 0)
        {
            cnt[j] += (val & 1);
            j++;
            val = (val >> 1);
        }
    }

    int p = 1, ans = 0;
    for(i=0; i<64; i++)
    {
        cnt[i]  %= 3;
        ans += (cnt[i]*p);
        p = (p << 1);
    }

    cout << ans << nn;
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



