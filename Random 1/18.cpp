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
    ll n, i, val, small_ev = LLONG_MAX, small_od = LLONG_MAX, flag_od = 0, flag_ev = 0, state;
    cin >> n;
    vector<ll> arr;
    for(i=0; i<n; i++)
    {
        cin >> val;
        if(i % 2 == 0) small_ev = min(small_ev, val);
        else small_od = min(small_od, val);
        arr.push_back(val);
    }

    if(n == 2)
    {
        if(arr[0] % arr[1] == 0 || arr[1] % arr[0] == 0) cout << 0 << nn;
        else cout << arr[0] << nn;
    }
    else if(n == 3)
    {
             if(arr[0] % arr[2] == 0 && arr[1] % arr[2] != 0) cout << arr[2] << nn;
        else if(arr[2] % arr[0] == 0 && arr[1] % arr[0] != 0) cout << arr[0] << nn;
        else if(arr[0] % arr[1] == 0 || arr[1] % arr[0] == 0) cout << 0 << nn;
        else if(arr[1] % arr[2] == 0 || arr[2] % arr[1] == 0) cout << 0 << nn;
        else                                                  cout << arr[0] << nn;
    }
    else
    {
        //let try with odd indexs
        for(i=1; i<n; i+=2)
        {
            if(arr[i] % small_od != 0)
            {
                flag_od = 1; //bug found
                break;
            }
        }
        if(flag_od == 0) //no bug and we need to proof
        {
            for(i=0; i<n; i++)
            {
                if(arr[i] % small_od == 0 && i == 0) state = 0;
                else if(arr[i] % small_od != 0 && i == 0) state = 1;

                else if(arr[i] % small_od == 0) state = 0;
                else if(arr[i] % small_od != 0) state = 1;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t; cin>>t; while(t--)
    solve();

    return 0;
}



