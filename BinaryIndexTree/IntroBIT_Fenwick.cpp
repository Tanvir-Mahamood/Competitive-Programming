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

#define mx 10000
int ar[mx];
int tree[mx];

int read(int idx) // query function, O(logn)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, int n)
{
    cout << "update: ";
    while(idx <= n)
    {
        cout << idx << " ";
        tree[idx] += val;
        idx += (idx & -idx);
    }
    cout << nn;
}

void print(int *ar, int n)
{
    for(int i=1; i<=n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << nn;
}

int normalQuery(int idx)
{
    int sum = 0;
    for(int i=1; i<=idx; i++)
    {
        sum += ar[i];
    }
    return sum;
}

void solve()
{
    int n, i;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> ar[i];
        update(i, ar[i], n); // tree construction : O(n*logn)
    }

    print(ar, n);
    cout << nn;
    print(tree, n);
    update(5,3,n);
}

int main() {
    //fastio;
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}



