// Postorder & Inorder
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

Node* buildTree(vector<int> postorder, vector<int> inorder, int Start, int End)
{
    static int idx = postorder.size()-1;

    if(Start > End) return NULL;

    int curr = postorder[idx];
    idx--;
    Node* node = new Node(curr);

    if(Start == End) return node;

    int pos = Search(inorder, Start, End, curr);

    node->right = buildTree(postorder, inorder, pos+1, End);
    node->left = buildTree(postorder, inorder, Start, pos-1);

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
    vector<int> postorder = {4,2,5,3,1};
    vector<int> inorder = {4,2,1,5,3};

    Node* root = buildTree(postorder, inorder, 0, postorder.size()-1);
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



