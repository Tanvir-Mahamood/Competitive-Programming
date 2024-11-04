#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000; // Maximum number of elements
int parent[MAXN];
int n;

void makeSet(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = -1;
    }
}

/*int find(int a) //Recursive function
{
    if(parent[a] < 0) return a;
    else return find(parent[a]);
}*/
int find(int a) //Iterative function
{
    while(1)
    {
        if(n==parent[n]) return n;
        else n=parent[n];
    }
}

void unite(int a, int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return;
    else parent[a]=b;
}

int main()
{
    int n,i,a,b,r;
    cin>>n>>r;
    makeSet(n);
    while(r--)
    {
        cin>>a>>b;
        a=find(a);
        b=find(b);
        if(a != b) unite(a,b);
    }

    for(i=1;i<=n;i++)
    {
        cout<<parent[i]<<" ";
    }

    return 0;
}



