#include <bits/stdc++.h>
using namespace std;

#define nn     "\n"
#define ll     long long
#define ull    unsigned long long
#define yes    cout<<"YES\n"
#define no     cout<<"NO\n"
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
#define mod    1000000007
#define PI     3.141592653589793238462

void solve()
{
    // basing vector of string input & output
//    int n, i;
//    cin >> n;
//    cin.get();
//    vector<string> str(n);
//    for(i=0; i<n; i++)
//    {
//        getline(cin, str[i]);
//    }
//    for(string it: str) cout << it << " ";

    string str = "This is my laptop";

    //char *ptr = strtok(const_cast<char*>(str.c_str()), " ");
    //cout << ptr << nn;

    vector<string> stor;

    char *ptr = strtok(const_cast<char*>(str.c_str()), " ");
    while(ptr != nullptr)
    {
        stor.push_back(string(ptr));
        ptr = strtok(nullptr, " ");
    }
    for(string it: stor) cout << it << nn;

}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}



