#include <bits/stdc++.h>
using namespace std;

#define nn   "\n"
#define ll   long long
#define ull  unsigned long long
#define yes  cout<<"YES\n"
#define no   cout<<"NO\n"
#define mod  1000000007
#define PI   3.141592653589793238462

int exp(int a, int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res*=a;
        b/=2;
        a*=a;
    }
    return res;
}

int main()
{
    int n, m, i, cnt, nod, sod, pod;
    cin >> n;
    m = n;

    vector<pair<int,int>> vp;

    for(i=2; i*i<=n; i++)
    {
        cnt=0;
        while(n%i==0)
        {
            cnt++;
            n /= i;
        }
        if(cnt!=0) vp.push_back({i,cnt});
    }
    if(n>1) vp.push_back({n,1}); //Prime Factorization

    nod = 1;
    for(auto it: vp) nod *= (it.second + 1);

    sod = 1;
    for(auto it: vp) sod *= (exp(it.first, it.second+1) - 1) / (it.first - 1);

    pod = 1;
    if(m & 1)  for(auto it: vp) pod *= exp(it.first, it.second/2);
    else pod = exp(m, nod/2);

    cout << "Number of divisors: " << nod << nn;
    cout << "Sum of divisors: " << sod << nn;
    cout << "Product of divisor: " << pod << nn;

}

