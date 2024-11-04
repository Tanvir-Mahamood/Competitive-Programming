//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

void solve()
{
    string txt,temp;
    getline(cin,txt);
    vector<string> v;
    int i;
    for(i=0;i<txt.size();i++)
    {
        if(txt[i] != ' ') temp.push_back(txt[i]);
        else
        {
            v.push_back(temp);
            temp.clear();
        }
    }
    v.push_back(temp);
    for(i=0;i<v.size();i++) cout<<v[i]<<nn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}




