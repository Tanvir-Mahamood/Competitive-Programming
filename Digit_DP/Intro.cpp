// Find the count of numbers between L to R which have a sum of digits equal to x
// 1 <= L <= R <= 10^18
// 1 <= x <= 180

/*
prob1: how many number x from the range [0,R] that obeys f(x)
prob2: how many number x from the range [L,R] that obeys f(x)

Sol1: S(R) = count the number of x that in the range obeys f(X)
Sol2: S(R) - S(L-1)
*/

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

int dp[101][181][2];

int solve(string &num, int n, int x, bool tight) // (R, n digits, sum x, tight)
{
    if(x < 0) return 0; // base case
    if(n == 1) // base case
    {
        if(x >= 0 && x <= 9) return 1; // return cnt
        else return 0;
    }

    if(dp[n][x][tight] != -1) return dp[n][x][tight]; // memoziation

    int answer = 0;
    int ub = tight ? num[num.length()-n]-'0' : 9;

    for(int dig=0; dig<=ub; dig++)
    {
        answer += solve(num, n-1, x-dig, (tight & (dig == ub)));
    }
    return dp[n][x][tight] = answer;
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        memset(dp, -1, sizeof(dp));
        string L, R = "11235";
        cout << solve(R, R.length(), 5, 1); //(R from [0-R], no. of digit, sum, tight status)
    }

    return 0;
}



