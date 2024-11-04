//In the name of Allah, the Gracious, the Merciful
#include <bits/stdc++.h>
#define nn "\n"
#define ll long long
#define ull unsigned long long
using namespace std;

int GCD(int a,int b)
{
    if(b==0) return a;
    else return GCD(b,a%b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num1,num2;
    cin>>num1>>num2;
    cout<<GCD(num1,num2)<<nn;

    return 0;
}

