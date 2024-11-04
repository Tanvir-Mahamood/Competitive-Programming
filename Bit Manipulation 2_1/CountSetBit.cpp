//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

int CountSetBit(int n)
{
    int cnt = 0;
    while(n > 0)
    {
        cnt += (n & 1);
        n >>= 1;
    }
    return cnt;
}

void solve()
{
    int n1, n2, i, cnt = 0;
    cin >> n1 >> n2;
    for(i=n1; i<=n2; i++)
    {
        if((i & 1) == 0 && i < n2)
        {
            cnt += 2 * CountSetBit(i) + 1;
            i++;
            continue;
        }
        cnt += CountSetBit(i);
    }
    cout << cnt << nn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}




