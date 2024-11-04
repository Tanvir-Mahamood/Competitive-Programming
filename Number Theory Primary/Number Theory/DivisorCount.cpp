//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
using namespace std;


int divcnt(int L,int R)
{
    int di[n+1] {0};
    int i,j,sum=0;
    for(i=L;i<=R;i++)
    {
        for(j=1;j*i<=R;j++)
        {
            di[i*j]++;
        }
    }
    for(i=L;i<=10;i++) sum+=di[i];
    return sum;
}

void solve()
{
    int L,R,n=0;
    cin>>L>>R;

    n+=divcnt(L,R);

    cout<<n<<nn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}


