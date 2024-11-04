#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000; // Maximum number of elements
int parent[MAXN];

void makeSet(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = -1;
    }
}

int find(int a) //Recursive function
{
    if(parent[a]<0) return a;
    return parent[a]=find(parent[a]);
}

/*int find(int a) //Recursive function
{
    if(parent[a] < 0) return a;
    else
    {
        int x=find(parent[a]);
        parent[a]=x;
        return x;
    }
}
int find(int a) //Iterative function
{
    vector<int> v;
    while(parent[a]>0)
    {
        v.push_back(a);
        a=parent[a];
    }
    for(int i=0;i<v.size();i++)
        parent[v[i]]=a;
    return a;
}*/

void unite(int a, int b)
{
    parent[a]+=parent[b];
    parent[b]=a;
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



