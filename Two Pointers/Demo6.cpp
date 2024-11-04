//Find all triplets such t sum of two elements is equal to the third one
//Complexity: O(n^2)
#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n)
{
      int i,x,l,r,sum,flag=1;
      for(i=n-1;i>=0;i--)
      {
          x=arr[i];
          l=0;
          r=i-1;
          while(l<r)
          {
              sum=arr[l]+arr[r];
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
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);

    solve(arr,n);

    return 0;
}


