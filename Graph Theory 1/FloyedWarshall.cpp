//All Pairs Shortest Path
#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

void floyd(vector<vector<int>> &graph, int n)
{
    int i, j, k;

    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(graph[i][j] > graph[i][k] + graph[k][j]) graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << nn;
    }
}
int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);

    int no_Node, no_Edge, i ,j, a, b, w;
    cin >> no_Node >> no_Edge;

    vector<vector<int>> graph(no_Node+1, vector<int>(no_Node+1));
    for(i=1; i<=no_Node; i++)
    {
        for(j=1; j<=no_Node; j++)
        {
            if(i == j) graph[i][j] = 0;
            else graph[i][j] = 1e9+7;
        }
    }

    while(no_Edge--)
    {
        cin >> a >> b >> w;
        graph[a][b] = w;
    }

    floyd(graph, no_Node);

    return 0;
}

/*
4 7
1 2 3
2 1 8
1 4 7
4 1 2
3 4 1
3 1 5
2 3 2
*/


