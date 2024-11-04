//Checking for i-th bit is set or not
//Using Right Shift

#include<bits/stdc++.h>
using namespace std;

bool check(int n,int i)
{
    if(((n>>i)&1) != 0) return true; //Set
    else return false;               //Not Set
}

int main()
{
    int n,i;
    cout<<"Enter number and i=";
    cin>>n>>i;
    bool ans=check(n,i);

    if(ans==true) cout<<"Set. I mean 1\n";
    else cout<<"Not set. I mean 0\n";

    return 0;
}
