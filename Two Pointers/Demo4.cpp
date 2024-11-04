//Find all triplets with zero sum
//Complexity: O(n^2)
#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n)
{
    int i,j,x;
    for(i=0;i<n-1;i++)
    {
        unordered_set<int> s;
        for(j=i+1;j<n;j++)
        {
            x=-(arr[i]+arr[j]);
            if(s.find(x) != s.end()) cout<<"("<<x<<","<<arr[i]<<","<<arr[j]<<")\n";
            else s.insert(arr[j]);
        }
    }
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
