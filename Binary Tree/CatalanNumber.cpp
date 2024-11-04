#include <bits/stdc++.h>
using namespace std;

#define nn     "\n"
#define ll     long long
#define ull    unsigned long long
#define yes    cout<<"YES\n"
#define no     cout<<"NO\n"
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
#define mod    1000000007
#define PI     3.141592653589793238462

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int catalan1(int n)
{
    if(n <= 1) return 1;

    int res = 0;
    for(int i=0; i<n; i++)
    {
        res += (catalan1(i) * catalan1(n-i-1));
    }
    return res;
}

vector<Node*> constructTrees(int Start, int End)
{
    vector<Node*> trees;
    if(Start > End)
    {
        trees.push_back(NULL);
        return trees;
    }
    for(int i=Start; i<=End; i++)
    {
        vector<Node*> leftSubtrees = constructTrees(Start, i-1);
        vector<Node*> rightSubtrees = constructTrees(i+1, End);

        for(int j=0; j<leftSubtrees.size(); j++)
        {
            Node* left = leftSubtrees[j];
            for(int k=0; k<rightSubtrees.size(); k++)
            {
                Node* right = rightSubtrees[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preorder(Node* root)
{
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    for(int i=0; i<10; i++)
    {
        cout << catalan1(i) << " ";
    }
    cout << nn;
    vector<Node*> totaltrees = constructTrees(1,3);
    for(int i=0; i<totaltrees.size(); i++)
    {
        cout  << i+1 << " : ";
            preorder(totaltrees[i]); cout << nn;
    }

    return 0;
}



