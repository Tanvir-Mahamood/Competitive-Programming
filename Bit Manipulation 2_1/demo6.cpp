//Checking a number can be expressed as power of 2
//Rule-2

#include<bits/stdc++.h>
using namespace std;

bool ck(int n)
{
    if((n&(n-1))==0) return true;
    else return false;
}

int main()
{
    int n;
    cin>>n;
    bool ans=ck(n);
    if(ans==true) cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}


