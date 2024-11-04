#include <bits/stdc++.h>
using namespace std;

#define nn     "\n"
#define ll     long long
#define ull    unsigned long long
#define yes    cout<<"YES\n"
#define no     cout<<"NO\n"
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
#define mod    1000000000
#define PI     3.141592653589793238462

vector<ll> a, b, c;
ll k;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B) // return C = (A X B)
{
    ll i, j, x;
    vector<vector<ll>> C(k+1, vector<ll>(k+1));

    for(i=1; i<=k; i++)
    {
        for(j=1; j<=k; j++)
        {
            for(x=1; x<=k; x++)
            {
                //C[i][j] += (A[i][x] * B[x][j])
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % mod) % mod;
            }
        }
    }
    return C;
}

vector<vector<ll>> power(vector<vector<ll>> A, ll p) // return matrix A^p
{
    if(p == 1) return A;

    if(p & 1) return multiply(A, power(A, p-1));
    vector<vector<ll>> X = power(A, p/2);

    return multiply(X, X);
}

ll compute(ll n)
{
    ll i, j;
    if(n == 0) return 0;
    if(n <= k) return b[n-1];

    // otherwise use matrix exponentiation
    vector<ll> F1(k+1); // indexing from 1

    for(i=1; i<=k; i++) F1[i] = b[i-1];

    vector<vector<ll>> T(k+1, vector<ll>(k+1)); // Transformation Matrix

    for(i=1; i<=k; i++)
    {
        for(j=1; j<=k; j++)
        {
            if(i < k)
            {
                (j == i+1) ? T[i][j] = 1 : T[i][j] = 0;
            }
            else T[i][j] = c[k-j];
        }
    }

    T = power(T, n-1);

    ll res = 0;
    for(i=1; i<=k; i++)
    {
        res = (res + (T[1][i] * F1[i]) % mod) % mod;
    }
    return res;
}

void solve()
{
    ll i, val, n;

    cin >> k;
    for(i=0; i<k; i++) // initial k terms
    {
        cin >> val;
        b.push_back(val);
    }

    for(i=0; i<k; i++) // coefficientt
    {
        cin >> val;
        c.push_back(val);
    }

    cin >> n;
    cout << compute(n) << nn;

    b.clear();
    c.clear();
}

int main() {
    fastio;
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}



