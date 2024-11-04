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
int Size[MAXN];

void make_set(int v)
{
    for(int i=0; i<=v; i++) parent[i] = i, Size[i] = 1;
}

int find_set(int v) //Optimized by Path Compression
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) //Optimized by using Union by Size
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if(Size[a] < Size[b]) swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];
    }
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

    cout << "\nVertex-Parent\n";
    for(i=1; i<=n; i++)
    {
        cout << i <<" " << parent[i] << nn;
    }


    return 0;
}

/*
Complexity: O( alpha(n) )
alpha(n) is called reverse ackerman function
almost constant complexity
*/




