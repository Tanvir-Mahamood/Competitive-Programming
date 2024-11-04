//Find all triplets that sum is equal to x
//Complexity: O(n^2)
#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n,int x)
{
      int flag=1,i,l,r,sum;
      for(i=0;i<n;i++)
      {
          l=i+1;
          r=n-1;
          while(l<r)
          {
              sum=arr[i]+arr[l]+arr[r];
              if(sum==x)
              {
                  cout<<"("<<arr[i]<<","<<arr[l]<<","<<arr[r]<<")\n";
                  flag=0;
              }
              if(sum>x) r--;
              else l++;
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

