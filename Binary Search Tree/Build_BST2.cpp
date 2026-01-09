// Build a balanced Binary Search Tree from sorted array
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

Node* constructBST(vector<int> arr, int Start, int End) // Divide & Conquer
{
    if(Start > End) return NULL;

    int mid = (Start+End) / 2;
    Node* root = new Node(arr[mid]);

    root->left = constructBST(arr, Start, mid-1);
    root->right = constructBST(arr, mid+1, End);

    return root;
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
    vector<int> arr = {10,20,30,40,50};
    int n = arr.size();

    Node* root = constructBST(arr, 0, n-1);
    Print_preorder(root);
}

int main() {
    //fastio;
    int t = 1;
    //cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}





