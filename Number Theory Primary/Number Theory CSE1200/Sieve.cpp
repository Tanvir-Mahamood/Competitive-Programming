//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

void sieve(int n)
{
    int i,j;
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(i=2;i*i<=n;i++)
    {
        if(prime[i]==true)
        {
            for(j=i*2;j<=n;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    for(i=2;i<=n;i++)
    {
        if(prime[i]==true) cout<<i<<" ";
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    cout<<"Enter Range:";
    cin>>n;
    cout<<"Prime numbers from 1 to "<<n<<" are :";
    if(n<=1) cout<<" \n";
    else if(n==2) cout<<"2\n";
    else sieve(n);

    return 0;
}

