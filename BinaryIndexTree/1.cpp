#include<bits/stdc++.h>

using namespace std;

/*
    USE of Binary indexed tree
    to solve this problem.
    It can be easily solved using
    merge sort algorithm
*/
//Ref- find on geeeksforgeeks

//Find sum of numbers less than current
//number
long findSum(int arr[],int idx)
{
    long sum = 0;
    while(idx > 0)
    {
        sum += arr[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

//Update the number and numbers that can use it
void update(int bit[],int n,int idx,int val)
{
    while(idx <= n)
    {
        bit[idx] += val;
        idx += (idx & (-idx));
    }
}

//Convert this array into relative array
//from lowest to highest. for example
//{8,4,3,5} will be {4,2,1,3}
void convert(vector<int> &arr,int n)
{
    vector<int> temp(n, 0);
    temp = arr;
    sort(temp.begin(), temp.end());
    for(int i=0; i<n; i++)
    {
        arr[i] = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin() + 1;
    }
}

/*

1
5
2 3 8 6 1

*/

//Find number of inversions
long long findInvCount(vector<int> &arr,int n)
{

    //Convert the array into size of n
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    convert(arr,n);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //Number of inversions
    long long invCnt = 0;

    //Take binary indexed tree array
    int bit[n+1];

    //Initialize it equal to zero
    memset(bit,0,sizeof bit);

    //Now find the inversion from right to left
    //As if some numbers are coming on left of
    //current number then they will give inversion
    for(int i= n-1 ; i>=0; i--)
    {

        //Find numbers that are already present
        //On left of this number that are greater
        //than this number
        invCnt += findSum(bit,arr[i]);

        //Add current number to binary index trees
        update(bit,n,arr[i],1);
    }

    //Return number of inversions
    return invCnt;
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        //int arr[n];
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++) cin>>arr[i];

        cout << findInvCount(arr,n) << endl;

    }
}
