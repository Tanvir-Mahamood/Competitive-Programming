//In the name of Allah, the Gracious, the Merciful
#include<bits/stdc++.h>
using namespace std;
int vis[1001];
vector<int> ar[1001];

void dfs(int node)
{
    int i, child;
    vis[node] = 1;
    cout << node << "-> ";
    for(i=0; i<ar[node].size(); i++)
    {
        child = ar[node][i];
        if(vis[child] == 0) dfs(child);
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    int no_Node, no_Edge, i, a, b;
    cin >> no_Node >> no_Edge;

    while(no_Edge--)  //Input
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    dfs(1);

    return 0;
}





//In the name of Allah, the Gracious, the Merciful
//#include<bits/stdc++.h>
//using namespace std;
//int vis[1001], deg[1001], res[1001];
//vector<int> ar[1001];
//
//void dfs(int node, int par)
//{
//    int i;
//    vis[node]=1;
//    //cout << node << " " << par << endl;
//    for(int child : ar[node])
//    {
//
//        if(vis[child]==0)
//        {
//            cout << child << " ";
//            dfs(child, node);
//            cout <<"after dfs " << child << endl;
//        }
//
//    }
//}
//
//int main()
//{
//    int no_Node, no_Edge, i, a, b;
//    cin >> no_Node;
//    no_Edge = no_Node - 1;
//
//    while(no_Edge--)  //Input
//    {
//        cin >> a >> b;
//        ar[a].push_back(b);
//        ar[b].push_back(a);
//
//        deg[a]++;
//        deg[b]++;
//    }
//
//    for(i=2; i<=no_Node; i++)
//    {
//        if(deg[i] == 1) res[i] = 1;
//    }
//
//    dfs(1, 0);
//
//    //for(i=1; i<=no_Node; i++) cout << res[i] << " ";
//
//
//    return 0;
//}

/*
9
1 2
2 3
3 4
3 5
5 6
5 7
6 8
6 9
*/









