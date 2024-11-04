//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

int maxSum(int a[],int n)
{
    int dp[100]={0};
    dp[0]= (a[0]>0)?a[0]:0;
    int max_so_far=dp[0];

    for(int i=1;i<n;i++)
    {
        dp[i]=dp[i-1]+a[i];

        if(dp[i]<0) dp[i]=0;

        max_so_far=max(dp[i],max_so_far);
    }
    return max_so_far;
}

//Space Optimized Code
//Kadane's Algorithm
int maxSumSpaceOpt(int a[],int n)
{
    int current_sum=0;
    int max_so_far=0;

    for(int i=0;i<n;i++)
    {
        current_sum+=a[i];
        if(current_sum<0) current_sum=0;

        max_so_far=max(current_sum,max_so_far);
    }
    return max_so_far;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int arr[]={-3,2,5,-1,6,3,-2,7,-5,2};
    int n=sizeof(arr)/sizeof(int);

    cout<<maxSum(arr,n)<<nn;
    cout<<maxSumSpaceOpt(arr,n)<<nn;

    return 0;
}

/*
arr=  -3  2  5 -1  6    3  -2   7  -5   2
dp =   0  2  7  6  12  15  13  20  15  17
maxx=  0  2  7  7  12  15  15  20  20  20
*/



