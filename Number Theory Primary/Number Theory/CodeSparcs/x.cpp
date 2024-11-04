//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

void solve()
{
    ll n,x,y,p,ans,mov;
    cin>>n>>x>>y>>p;
    if(x==y) cout<<"1\n";
    else
    {
        y++;
        if(x%2 != 0 && p%2 != 0)
        {
            if(x>y) y=y+n;
            mov=y-x;
            ans=ceil((double)mov/(p+1));
        }
        else if(x%2 != 0 && p%2==0)
        {
            if(x>y) y=y+n;
            mov=y-x;
            ans=ceil((double)mov/(p+4));
        }
        else if(x%2==0 && p%2 != 0)
        {
            if(x>y) y=y+n;
            x=x+p+2;
            if(x>y) y=y+n;
            mov=y-x;
            ans=ceil((double)mov/(p+1))+1;
        }
        else if(x%2==0 && p%2==0)
        {
            if(x>y) y=y+n;
            x=x+p+1;
            if(x>y) y=y+n;
            mov=y-x;
            ans=ceil((double)mov/(p+2))+1;
        }
        cout<<ans<<nn;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t,i;
    cin>>t;
    for(i=0; i<t; i++)
    {
        solve();
    }

    return 0;
}
