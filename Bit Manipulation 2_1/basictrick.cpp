#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

void printBinary(int num)
{
    for(int i=10; i>=0; --i)
    {
        cout << ((num >> i) & 1);
    }
    cout << nn;
}
void solve()
{
    int n, i;
    cin >> n;
    printBinary(n);

    cout << "\nA to Z : \n\n";
    for(char c = 'A'; c <= 'Z'; ++c)
    {
        cout << c << " ";
        printBinary(int(c));
    }

    cout << "\na to z : \n\n";
    for(char c = 'a'; c <= 'z'; ++c)
    {
        cout << c << " ";
        printBinary(int(c));
    }

    //capital to small conversion and vice-versa
    char A = 'A';
    char a = A | (1 << 5);
    cout << a << nn;
    cout << (char)(a & ( ~(1 << 5))) << nn;

    char B = 'B';
    char b = (B | ' ');   cout << b << nn;

    char d = 'd';
    char D = (d & '_');   cout << D << nn;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //ll t; cin>>t; while(t--)
    solve();

    return 0;
}



