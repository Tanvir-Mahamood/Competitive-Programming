//Find the pair whose sum is closest to x.
//Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

void solve(int arr[],int n,int x)
{
    int l,r,sum,flag=1,ind1,ind2,diff;
    l=0;
    r=n-1;
    diff=INT_MAX;
    while(l<r)
    {
        sum=arr[l]+arr[r];
        if(abs(sum-x)<diff)
        {
            ind1=l;
            ind2=r;
            diff=abs(sum-x);
            flag=0;
        }
        if(sum>x) r--;
        else l++;
    }
    if(flag) cout<<"Not found\n";
    else cout<<"("<<arr[ind1]<<","<<arr[ind2]<<")\n";
}

int main()
{
    int n,i,x;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    cin>>x;

    solve(arr,n,x);

    return 0;
}

