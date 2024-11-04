//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

void solve()
{
    int n,r;
    char ch;
    cin>>n;
    string ans;
    while(n>0)
    {
        r=n%10;
        ch=r+'0';
        ans+=ch; //ans.push_back(ch);
        n/=10;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<nn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}


