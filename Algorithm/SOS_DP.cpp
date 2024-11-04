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

void solve1() // O(4^n)
{
    int n, i, t, x;
    cin >> n;
    int f[1<<n];
    for(i=0; i<(1<<n); i++)
    {
        cin >> f[i];
    }

    int h[1<<n];

    for(t=0; t<(1<<n); t++)
    {
        h[t] = 0;
        //cout << "t= " << t << " ";
        for(x=0; x<(1<<n); x++)
        {
            if((t & x) == x)
            {
                h[t] += f[x];
                //cout << x << " ";
            }
        }
        //cout << nn;
    }


    for(i=0; i<(1<<n); i++)
    {
        cout << h[i] << " ";
    }
    cout << nn;
}

void solve2() // O(3^n)
{
    int n, i, t, x;
    cin >> n;
    int f[1<<n];
    for(i=0; i<(1<<n); i++)
    {
        cin >> f[i];
    }

    int h[1<<n];

    for(t=0; t<(1<<n); t++)
    {
        h[t] = 0;
        //cout << "t= " << t << " ";
        x = 0;
        for(x=t; x>0; x=((x-1)&t))// x only go to subsets of t
        {
            h[t] += f[x];
            //cout << x << " ";
        }
        //cout << "0 ";
        h[t] += f[0];
        //cout << nn;
    }


    for(i=0; i<(1<<n); i++)
    {
        cout << h[i] << " ";
    }
    cout << nn;
}

void solve3() // O(n*2^n) // Dynamic Programming
{
    int n, i, t, x;
    cin >> n;
    int f[1<<n];
    for(i=0; i<(1<<n); i++)
    {
        cin >> f[i];
    }

    int dp[1<<n][n+1];
    for(t=0; t<(1<<n); t++) //base case
    {
        dp[t][0] = f[t];
    }
    for(t=0; t<(1<<n); t++)
    {
        for(i=1; i<=n; i++)
        {
            if(t&(1<<(i-1))) // if i-th bit is on
            {
                dp[t][i] = dp[t][i-1] + dp[t^(1<<(i-1))][i-1];
            }
            else // if i-th bit is off
            {
                dp[t][i] = dp[t][i-1];
            }
        }
    }


    int h[1<<n];

    for(t=0; t<(1<<n); t++)
    {
        h[t] = dp[t][n];
    }


    for(i=0; i<(1<<n); i++)
    {
        cout << h[i] << " ";
    }
    cout << nn;
}

int main() {
    //fastio;
    //int t;  cin>>t;  for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": ";
        solve1(); //Bruteforce
        solve2(); //Suboptimal Solution
        solve3(); //SoS Dynamic Programming solution
    }

    return 0;
}




