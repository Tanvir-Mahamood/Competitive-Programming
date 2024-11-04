//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

void solve()
{
    cout<<"Enter a String:\n";
    string s;
    cin>>s;
    while(next_permutation(s.begin(),s.end())) cout<<s<<nn;

    //Store the ans in a List to make it unique and sorted

    cout<<"Enter a Vector:\n";
    int n,i;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++) cin>>v[i];
    while(next_permutation(v.begin(),v.end()))
    {
        for(i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<nn;
    }

}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}


