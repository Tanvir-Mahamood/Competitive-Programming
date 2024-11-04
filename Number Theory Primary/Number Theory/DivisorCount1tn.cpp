#include<bits/stdc++.h>
#define nn "\n"
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,i,j;
    cin>>n;
    int div[n+1] {0};
    for(i=1;i<=n;i++)
    {
        for(j=1;j*i<=n;j++)
        {
            div[i*j]++;
        }
    }
    for(i=1;i<=n;i++) cout<<"Amount of divisor of digit "<<i<<"="<<div[i]<<nn;
    return 0;
}



