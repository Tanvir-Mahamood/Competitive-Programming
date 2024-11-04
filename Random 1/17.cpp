//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

void solve()
{
    ll n, i, val, flag_od = 0, flag_ev = 0, small_ev = LLONG_MAX, small_od = LLONG_MAX;
    cin >> n;
    vector<ll> ev, od;
    for(i=0; i<n; i++)
    {
        cin >> val;

        if(i % 2) //odd
        {
            small_od = min(small_od , val);
            od.push_back(val);
        }
        else //even
        {
            small_ev = min(small_ev , val);
            ev.push_back(val);
        }
    }

    if(n == 2)
    {
        if(ev[0] % od[0] == 0 || od[0] % ev[0] == 0) cout << 0 << nn;
        else                                         cout << ev[0] << nn;
        return;
    }

    if(n == 3)
    {
             if(ev[0] % ev[1] == 0 && od[0] % ev[1] != 0) cout << ev[1] << nn;
        else if(ev[1] % ev[0] == 0 && od[0] % ev[0] != 0) cout << ev[0] << nn;
        else if(ev[0] % od[0] == 0 || od[0] % ev[0] == 0) cout << 0 << nn;
        else if(ev[1] % od[0] == 0 || od[0] % ev[1] == 0) cout << 0 << nn;
        else                                              cout << ev[0] << nn;
        return;
    }

    for(i=0; i<od.size(); i++)
    {
        if(od[i] % small_od != 0)
        {
            flag_od = 1; //bug found
            break;
        }
    }
    for(i=0; i<ev.size(); i++)
    {
        if(ev[i] % small_ev != 0)
        {
            flag_ev = 1; //bug found
            break;
        }
    }

    if(flag_ev == 1 && flag_od == 1) cout << 0 << nn;
    else
    {
        if(small_ev == 1 && small_od == 1) cout << 0 << nn;
        else if(small_od == 1)             cout << small_ev << nn;
        else                               cout << small_od << nn;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t; cin>>t; while(t--)
    solve();

    return 0;
}



