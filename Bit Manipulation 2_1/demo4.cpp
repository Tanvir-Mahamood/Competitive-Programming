//Counting number of set bit
//Using Left Shift

#include<bits/stdc++.h>
using namespace std;

int bit_cnt(int n)
{
    int cnt=0,i;
    for(i=0;i<32;i++)
    {
        if((n&(1<<i)) != 0) cnt++;
    }
    return cnt;
}

int main()
{
    int n,ans;
    cin>>n;
    ans=bit_cnt(n);
    cout<<ans<<endl;

    return 0;
}

