//Given an array. Determine the number of sub-arrays with a fixed sum

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

void solve()
{
    int n, i, cnt = 0, sum;
    cin >> n >> sum;
    vector<int> v(n);
    for(i=0; i<n; i++) cin>>v[i];
    partial_sum(v.begin(),v.end(),v.begin());
    map<int, int> mp;
//    for(i=0; i<n; i++)
//    {
//        mp[v[i]]++;
//    }
//    for(i=n-1; i>=0; i--)
//    {
//        cnt += mp[v[i] - sum];
//    }

    for(i=0; i<n; i++)
    {
        cnt += mp[v[i] - sum];
        mp[v[i]]++;
    }

    cout << cnt << nn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}



