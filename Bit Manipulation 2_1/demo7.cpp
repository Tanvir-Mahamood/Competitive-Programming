/*All Pair Sum Xor
For example,
    A=2,3,5
    ans=(2+2)^(2+3)^(2+5)^
        (3+2)^(3+3)^(3+5)^
        (5+2)^(5+3)^(5+5)

        = (2+2)^(3+3)^(5+5)
        = (2*2)^(2*3)^(2*5)
*/

#include<bits/stdc++.h>
using namespace std;

int operation(int arr[],int n)
{
    int i,sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum^(2*arr[i]);
    }
    return sum;
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



