/*
What is the minimum number of people that should be present in a hall
so that there's 50% chance of two people having the same birthday.
*/

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

int main() {
    float x = 1.0;
    int people = 0;

    float num = 365, denom = 365;

    float thresold = 0.5; // u may take user input

    if(thresold == 1.0)
    {
        cout << 365 << nn;
        return 0;
    }

    // we will have observed how many people having different birthday date.
    while(x > 1-thresold)
    {
        x = x*(num)/denom;
        num--;
        people++;

        cout << people << " " << x << nn;
    }

    return 0;
}



