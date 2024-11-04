//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

int findMinRec(int A[], int n)
{
    if (n == 1) return A[0];
    return min(A[n-1], findMinRec(A, n-1));
}

int findMaxRec(int A[], int n)
{
    if (n == 1)  return A[0];
    return max(A[n-1], findMaxRec(A, n-1));
}

int main() {
    int n, i;
    cin >> n;
    int arr[n];
    for(i=0; i<n; i++) cin >> arr[i];
    cout << findMinRec(arr, n) << nn;
    cout << findMaxRec(arr, n) << nn;


    return 0;
}



