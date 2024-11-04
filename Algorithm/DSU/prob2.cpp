//https://assessment.hackerearth.com/challenges/college/codemania-20/algorithm/owl-fight/

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
    for(int i=0; i<=v; i++) parent[i] = (i * -1), Size[i] = 1;
}

int find_set(int v) //Optimized by Path Compression
{
//    if (v == parent[v]) return v;
//    return parent[v] = find_set(parent[v]);

    if(parent[v] < 0) return v;

    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) //Optimized by using Union by Size
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if(Size[a] < Size[b]) swap(a, b);
        parent[a] = min(parent[a], parent[b]);
        parent[b] = a;
        Size[a] += Size[b];
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, r, a, b, i, q;
    cin >> n >> r;
    make_set(n);

    while(r--)
    {
        cin >> a >> b;
        union_sets(a, b);
    }

    /*for(i=1; i<=n; i++)
    {
        cout << i <<" " << parent[i] << nn;
    }*/
    cin >> q;
    while(q--)
    {
        cin >> a >> b;
        int par_a = find_set(a);
        int par_b = find_set(b);

        if(par_a == par_b) cout << "TIE\n";
        else
        {
            if(parent[par_a] < parent[par_b]) cout << a << nn;
            else cout << b << nn;
        }
    }


    return 0;
}







