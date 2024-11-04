#include<bits/stdc++.h>
#define nn "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,i,j;
    cin>>n;
    int a[n+1] {0};
    for(i=2;i*i<=n;i++)
    {
        if(a[i]==0)
        {
            for(j=i*i;j<=n;j++) a[j]=1;
        }
    }
    for(i=0;i<=n;i++)
    {
        if(a[i]==0) cout<<i<<" ";
    }
    return 0;
}



