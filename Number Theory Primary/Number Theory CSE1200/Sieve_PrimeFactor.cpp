//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
using namespace std;

//Both distinct & non-distinct factors

bool prime[5000001];
vector<int> divi(5000001);
int N=5000001;

void sieve()
{
    int i,j,temp;
    divi[0]=0;
    divi[1]=1;
    for(i=2;i<=N;i++)
    {
        if(prime[i]==false)
        {
            for(j=i;j<=N;j+=i)
            {
                temp=j;
                while(temp%i==0)
                {
                    temp/=i;
                    divi[j]++;
                }
                prime[j]=true;
            }
        }
    }
}

void solve()
{
    /*ll a,b,ans;
    cin>>a>>b;
    ans=divi[a]-divi[b];
    cout<<ans<<nn;*/
    for(int i=1;i<=10;i++) cout<<divi[i]<<" ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*sieve();
    partial_sum(divi.begin(),divi.end(),divi.begin());
    ll t; cin>>t; while(t--)
    solve();*/

    sieve();
    solve();

    return 0;
}



