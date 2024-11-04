//Checking a number can be expressed as power of 2
//Rule-1

#include<bits/stdc++.h>
using namespace std;

int ck(int n)
{
    int cnt=0;
    while(n != 0)
    {
        if((n&1) != 0) cnt++;
        n=n>>1;
    }
    return cnt;
}

int main()
{
    int n,ans;
    cin>>n;
    ans=ck(n);
    if(ans==1) cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}

