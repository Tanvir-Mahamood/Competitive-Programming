//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

void solve()
{
    string str;
    getline(cin,str);
    int i,n=0;
    for(i=0;i<str.size();i++)
    {
        n=(n*10)+(str[i]-'0');
    }
    cout<<n<<nn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}


