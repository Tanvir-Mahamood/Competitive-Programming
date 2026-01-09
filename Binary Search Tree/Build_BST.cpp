// Build Binary Search Tree from Preorder
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

Node* constructBST(vector<int> preorder, int* preorderIdx, int key, int minn, int maxx, int n)
{
    if(*preorderIdx >= n) return NULL;

    Node* root = NULL;
    if(key > minn && key < maxx)
    {
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;

        if(*preorderIdx < n) root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx],minn, key, n);
        if(*preorderIdx < n) root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx],key, maxx, n);
    }
    return root; // null
}

void Print_preorder(Node* root)
{
    if(root == NULL) return;

    cout << root->data << " ";
    Print_preorder(root->left);
    Print_preorder(root->right);
}

void solve()
{
    vector<int> preorder = {10,2,1,13,11};
    int n = preorder.size();
    int preorderIdx = 0;

    Node* root = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n); // O(n)
    Print_preorder(root);
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}




