#include<bits/stdc++.h>
using namespace std;
//Lowest Common Ancestor,
//Binary Lifting

vector<int> ar[1001];
const int maxN=10;
int level[1001];
int LCA[1001][maxN+1];

void dfs(int node, int lvl, int par)
{
    level[node]  = lvl;
    LCA[node][0] = par;

    for(int child: ar[node])
    {
        if(child != par)
        {
            dfs(child, lvl+1, node);
        }
    }
    //0th column is ready
}

void init(int n)
{
    dfs(1,0,-1);

    for(int i=1; i<=maxN; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(LCA[j][i-1] != -1)
            {
                int par   = LCA[j][i-1];
                LCA[j][i] = LCA[par][i-1];
            }
        }
    }
    //Full Sparse table is ready
}

int getLCA(int a,int b)
{
    if(level[b] < level[a]) swap(a,b);
    int d = level[b]-level[a];
    while(d>0)
    {
        int i = log2(d);
        b = LCA[b][i];
        d -= (1<<i);
    }
    if(a == b) return a;

    for(int i=maxN; i>=0; i--)
    {
        if(LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
        {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    return LCA[a][0];
}

int getDist(int a, int b)
{
    int lca = getLCA(a, b);
    return level[a] + level[b] - 2*level[lca];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b, q, i;
    cin >> n;

    for(i=1; i<=n; i++)
    {
        for(int j=0; j<=maxN; j++)
        {
            LCA[i][j] = -1;
        }
    }

    for(i=1; i<n; i++)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    init(n); //Initialize LCA Array

    //for(i=1; i<=n; i++) cout << i << " " << level[i] << endl;


    cin >> q;
    while(q--)
    {
        cin >> a >> b;
        cout << getDist(a, b) << '\n';
    }

    return 0;
}




/*
10
1 2
2 6
2 9
6 8
9 5
1 3
3 4
4 10
4 7
3
8 9
5 10
10 7
*/

