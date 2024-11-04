//Find the pair from tow arrays whose sum is closest to x.
//Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

void solve(int arr[],int brr[],int n,int m,int x)
{
    int l,r,sum,flag=1,ind1,ind2,diff;
    l=0;
    r=n-1;
    diff=INT_MAX;
    while(l<n && r>=0)
    {
        sum=arr[l]+brr[r];
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
    else cout<<"("<<arr[ind1]<<","<<brr[ind2]<<")\n";
}

int main()
{
    int n,m,i,x;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);

    cin>>m;
    int brr[m];
    for(i=0;i<m;i++) cin>>brr[i];
    sort(brr,brr+m);

    cin>>x;

    solve(arr,brr,n,m,x);

    return 0;
}


