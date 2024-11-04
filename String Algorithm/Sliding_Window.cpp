//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

void solve()
{
    string text,pattern,temp;
    cin>>text;
    cin>>pattern;
    int cnt=0,i;
    for(i=0;i<pattern.size();i++)
        temp+=text[i]; //temp.push_back(text[i]);

    if(temp==pattern) cnt++;

    for(i=pattern.size();i<text.size();i++)
    {
        temp+=text[i]; //push_back
        temp.erase(temp.begin());
        if(temp==pattern) cnt++;
    }
    cout<<cnt<<nn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}


