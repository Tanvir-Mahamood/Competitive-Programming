//Not easy Math -Inclusion Exclusion

//Determine the number of numbers between 1 and n which are divisible by any of the prime numbers less han 20

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007
ll primes[] = {2,3,5,7,11,13,17,19};

void solve()
{
    ll n, i, j, ans = 0;
    cin >> n;
    ll subsets = (1 << 8) - 1;
    for(i=1; i<subsets; i++)
    {
        ll denom = 1LL;
        ll setBits = __builtin_popcount(i);
        for(j=0; j<=7; j++)
        {
            if(i & (1 << j)) denom = denom * primes[j];
        }
        if(setBits & 1)  ans += n / denom;
        else             ans -= n / denom;
    }
    cout << ans << nn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t; cin>>t; while(t--)
    solve();

    return 0;
}




