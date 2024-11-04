// Preorder & Inorder
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
    struct Node* left;
    struct Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int Search(vector<int> inorder, int Start, int End, int curr)
{
    for(int i=Start; i<=End; i++)
    {
        if(inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node* buildTree(vector<int> preorder, vector<int> inorder, int Start, int End)
{
    static int idx = 0;

    if(Start > End) return NULL;

    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);

    if(Start == End) return node;

    int pos = Search(inorder, Start, End, curr);
    node->left = buildTree(preorder, inorder, Start, pos-1);
    node->right = buildTree(preorder, inorder, pos+1, End);

    return node;
}

void inorder_Print(Node* root)
{
    if(root == NULL) return;

    inorder_Print(root->left);
    cout << root->data << " ";
    inorder_Print(root->right);
}

void solve1()
{
    vector<int> preorder = {1,2,4,3,5};
    vector<int> inorder = {4,2,1,5,3};

    Node* root = buildTree(preorder, inorder, 0, preorder.size()-1);
    inorder_Print(root);
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve1(); // Using Preorder & Inorder
        //solve2(); // Using Postorder & Inorder
    }

    return 0;
}


