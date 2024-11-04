/*
Problem Name: Count Number of Binary Strings

Problem Constraints: 1<=t<=100
1<=n<=90
Problem Description:
You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Input Format: First line contains integer t which is number of test case.
For each test case, it contains an integer n  which is the the length of Binary String.

Sample Input:
2
2
3
Output Format: Print the number of all possible binary strings.

Sample Output:
3
5
*/

#include <bits/stdc++.h>
using namespace std;

long long countStrings(int n)
{
    long long a[n], b[n];
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = (long long)(a[i-1] + b[i-1]); //Last Digit 0
        b[i] = (long long)a[i-1]; //Last Digit 1
    }
    return (long long)(a[n-1] + b[n-1]);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t,i,n;
    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>n;
        cout << countStrings(n) << endl;
    }
    return 0;
}

