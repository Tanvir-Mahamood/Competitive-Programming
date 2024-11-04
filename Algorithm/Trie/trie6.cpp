#include <bits/stdc++.h>
using namespace std;

#define nn  "\n"
#define ll  long long
#define ull unsigned long long
#define yes cout<<"YES\n"
#define no  cout<<"NO\n"
#define mod 1000000007

struct Node
{
    Node *links[2];
    bool ContainsKey(int bit)
    {
        return (links[bit] != NULL);
    }
    Node *get(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
private:
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    void Insert(int num)
    {
        Node* node = root;
        for(int i=31; i>=0; i--)
        {
            int bit = (num >> i) & 1;
            if(!node->ContainsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num)
    {
        Node* node = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--)
        {
            int bit = (num >> i) & 1;
            if(node->ContainsKey(1^bit))
            {
                maxNum = maxNum | (1<<i);
                node = node->get(1^bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

vector<int> maxXORQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    sort(arr.begin(), arr.end());
    int q = queries.size();

    vector<int> ans(q, 0);
    vector<pair<int, pair<int,int>>> oq; //offlineQueries, (ai, xi, i)

    int indx = 0;
    for(auto &it: queries) //itz a vector
    {
        oq.push_back({it[1],{it[0], indx++}});
    }
    sort(oq.begin(), oq.end());

    int i = 0;
    int n = arr.size();
    Trie trie;

    for(auto &it : oq)
    {
        while(i < n && arr[i] <= it.first)
        {
            trie.Insert(arr[i]);
            i++;
        }
        if(i != 0) ans[it.second.second] = trie.getMax(it.second.first);
        else ans[it.second.second] = -1;
    }
    return ans;
}

int main()
{
    int n, q, i, a, x;
    cin >> n >> q;
    vector<int> v(n);
    for(i=0; i<n; i++) cin >> v[i];

    vector<vector<int>> que(n,vector<int>(2));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++)
        {
            cin>>que[i][j];
        }
    }
    int result = maxXORQueries(v, que);
    cout << result << nn;

    return 0;
}




