#include<bits/stdc++.h>
using namespace std;
//Kruskal'S Minimum Spanning Tree

struct edge
{
    int a, b, w;
};

edge ar[100000];
int par[10001];
int Size[10001];

bool cmp(edge a, edge b)
{
    if(a.w < b.w) return true;
    return false;
}

int find_set(int v)
{
    if(par[v] == -1) return v;
    return par[v] = find_set(par[v]);
}

void union_set(int a,int b)
{
    //par[a] = b;
    if(Size[a] < Size[b]) swap(a, b);
    par[b] = a;
    Size[a] += Size[b];
}

int main()
{
    int n, m, a, b, w;
    cin >> n >> m;

    for(int i=1; i<=n; i++) par[i] = -1, Size[i] = 1;

    for(int i=0; i<m; i++) //IO
    {
        cin >> ar[i].a >> ar[i].b >> ar[i].w;
    }
    //sort(ar.begin(),ar.end());
    int sum=0;
    sort(ar, ar+m, cmp);

    for(int i=0; i<m; i++)
    {
        a = find_set(ar[i].a);
        b = find_set(ar[i].b);

        if(a != b)
        {
            sum += ar[i].w;
            union_set(a,b);
        }
    }
    cout << sum << "\n"; //Sum of edge in MST

    return 0;
}
