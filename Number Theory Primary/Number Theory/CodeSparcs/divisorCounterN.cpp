#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,i,cnt=0;
    cin>>n;
    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cnt++;
            if((n/i) != i) cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}

