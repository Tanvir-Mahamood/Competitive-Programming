#include <bits/stdc++.h>
using namespace std;

#define nn     "\n"
#define ll     long long
#define ull    unsigned long long
#define yes    cout<<"YES\n"
#define no     cout<<"NO\n"
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
#define mod    1000000007
#define PI     3.141592653589793238462

void multiply(int *a, int &n, int num)
{
    int carry = 0, i;
    for(i=0; i<n; i++)
    {
        int product = a[i] * num + carry;
        a[i] = product % 10;
        carry = product / 10;
    }
    while(carry)
    {
        a[n] = carry % 10;
        carry = carry / 10;
        n++;
    }
}

void big_factorial(int number)
{
    int *a = new int[1000];
    int i;
    for(i=0; i<1000; i++) a[i] = 0;

    a[0] = 1;
    int n = 1; // no. of digits
    for(i=2; i<=number; i++)
    {
        multiply(a, n, i);
    }
    for(i=n-1; i>=0; i--)
    {
        cout << a[i];
    }
    delete [] a;
}

int main() {

    int n;
    cin >> n;
    big_factorial(n);

    return 0;
}




