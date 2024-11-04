/*Total sum of all Pair Xor
For example,
    A=3,5,9
    ans=3^5+3^9+5^9
*/

#include<bits/stdc++.h>
using namespace std;

int operation(int arr[],int n)
{
    int ans=0,i,j,one,zero,p;

    for(i=0;i<31;i++)
    {
        one=zero=0;
        for(j=0;j<n;j++)
        {
            if(arr[j] & (1<<i)) one++;
            else zero++;
        }
        p=one*zero;
        ans+=(1<<i)*p;
    }
    return ans;
}

int main()
{
    int n,i,ans;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    ans=operation(arr,n);
    cout<<ans<<endl;

    return 0;
}
