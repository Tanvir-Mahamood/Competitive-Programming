//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn "\n"
#define ll long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
//Recursion Call Stack

//Time Complexity: O(2^N)
//Space Complexity: O(N)

int fibo(int n)
{
    if(n==0 || n==1) return n;
    else
    {
        int ans=fibo(n-1)+fibo(n-2);
        return ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    cout<<fibo(n)<<nn;

    return 0;
}




