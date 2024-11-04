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

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;
    for(auto &it: arr1) trie.Insert(it);
    int maxx = 0;
    for(auto &it: arr2)
    {
        maxx = max(maxx, trie.getMax(it));
    }
    return maxx;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(n);
    for(int i=0; i<n; i++) cin >> arr1[i];
    for(int i=0; i<m; i++) cin >> arr2[i];
    int result = maxXOR(n, m, arr1, arr2);
    cout << result << nn;

    return 0;
}



