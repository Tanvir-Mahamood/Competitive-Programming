//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
#define mod 1000000007
using namespace std;

ll Power_Mod(ll b,ll p)
{
    ll t;
    if(p==0) return 1;
    t=Power_Mod(b,p/2);
    if(p%2==0) return t*t%mod;
    else return b*t*t%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll b,p,ans;
    cin>>b>>p;
    ans=Power_Mod(b,p);
    cout<<ans<<nn;
    return 0;
}

