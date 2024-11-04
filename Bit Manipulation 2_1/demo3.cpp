//Counting number of set bit
//Using Right Shift

#include<bits/stdc++.h>
using namespace std;

int bit_cnt(int n)
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
    ans=bit_cnt(n);
    cout<<ans<<endl;

    return 0;
}
