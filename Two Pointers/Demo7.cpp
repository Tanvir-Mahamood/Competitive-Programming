//Find 4 elements that sum is equal to x
//Complexity: O(n^3)
#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n,int x)
{
    int flag=1,i,j,l,r,sum;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            l=j+1;
            r=n-1;
            while(l<r)
            {
                sum=arr[i]+arr[l]+arr[r]+arr[j];
                if(sum==x)
                {
                    cout<<"("<<arr[i]<<","<<arr[l]<<","<<arr[r]<<","<<arr[j]<<")\n";
                    flag=0;
                }
                if(sum>x) r--;
                else l++;
            }
        }
    }
    if(flag) cout<<"Not found\n";
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
