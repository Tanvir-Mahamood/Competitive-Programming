//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,i;
    cin>>n;

    while (n%2==0)
    {
        cout<<2<< " ";
        n=n/2;
    }
    for(i=3; i<=sqrt(n); i=i+2)
    {
        while(n%i==0)
        {
            cout<<i<<" ";
            n=n/i;
        }
    }
    if(n>2) cout<<n<< " ";

    return 0;
}

