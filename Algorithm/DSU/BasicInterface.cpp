//In the name of Allah, the Gracious, the Merciful

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

const int MAXN = 100000; // Maximum number of elements
int parent[MAXN];

void make_set(int v)
{
    for(int i=0; i<=v; i++) parent[i] = i;
}
/*
int find_set(int v) //Recursive
{
    if (v == parent[v]) return v;
    return find_set(parent[v]);
}
*/
int find_set(int v)
{
    while(1)
    {
        if(v == parent[v]) return v;
        else v = parent[v];
    }
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) parent[b] = a;
}



int main() {
    int n, r, a, b, i;
    cin >> n >> r;
    make_set(n);

    while(r--)
    {
        cin >> a >> b;
        union_sets(a, b);
    }

    for(i=1; i<=n; i++)
    {
        cout << i <<" " << parent[i] << nn;
    }


    return 0;
}



