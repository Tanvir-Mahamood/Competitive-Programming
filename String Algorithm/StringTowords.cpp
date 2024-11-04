//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

void solve()
{
    string str,word;
    getline(cin,str);
    istringstream iss(str);
    while(iss>>word)
    {
        cout<<word<<nn;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}


