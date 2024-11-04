#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n==2) return true;
    else if (n%2==0 || n==1) return false;

    for (int i=3;i*i<=n;i+=2)
    {
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    if (isPrime(n)) cout<<"prime number."<<endl;
    else cout<<"not a prime number."<<endl;

    return 0;
}

