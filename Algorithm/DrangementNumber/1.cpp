// A Naive Recursive program
//O(2^n)
#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

ll Derangement(int n) //count derangement numbers
{
    if (n == 1) return 0;
    if (n == 2) return 1;
    return (n - 1) * (Derangement(n - 1) + Derangement(n - 2));
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cin >> n;
    ll ans = Derangement(n);
    cout << ans << nn;
    return 0;
}


