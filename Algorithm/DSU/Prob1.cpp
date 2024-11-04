//https://www.hackerearth.com/problem/algorithm/teachers-dilemma-3-00955296/

#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

const int MAXN = 100005; // Maximum number of elements
int parent[MAXN];
int Size[MAXN];

void make_set(int v)
{
    for(int i=0; i<=v; i++) parent[i] = -1, Size[i] = 1;
}

int find_set(int v) //Optimized by Path Compression
{
    while(parent[v] > 0) v = parent[v];
    return v;
}

void union_sets(int a, int b) //Optimized by using Union by Size
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if(Size[a] < Size[b]) swap(a, b);
        //parent[a] += parent[b];
        parent[a] = (parent[a] + parent[b]) % mod;
        parent[b] = a;
        Size[a] += Size[b];
    }
}



int main() {
    int n, r, a, b, i;
    ll mul = 1;
    cin >> n >> r;
    make_set(n);

    while(r--) //IO
    {
        cin >> a >> b;
        union_sets(a, b);
    }

    for(i=1; i<=n; i++)
    {
        //cout << i <<" " << parent[i] << nn;
        if(parent[i] < 0) mul = (mul * abs(parent[i])) % mod;
    }
    cout << mul % mod << nn;

    return 0;
}

/*
Complexity: O( alpha(n) )
alpha(n) is called reverse ackerman function
almost constant complexity
*/





