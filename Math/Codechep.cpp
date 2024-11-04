// https://www.codechef.com/PRACTICE/problems-old/GRAYSC

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
    ll n, i, j, k, l;
    cin >> n;
    vector<ll> v(n);
    for(i=0; i<n; i++)
    {
        cin >> v[i];
    }
    if(n >= 130) yes;
    else // Bruteforce solution
    {
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                for(k=j+1; k<n; k++)
                {
                    for(l=k+1; l<n; l++)
                    {
                        if((v[i] ^ v[j] ^ v[k] ^ v[l]) == 0)
                        {
                            yes;
                            return;
                        }
                    }
                }
            }
        }
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



