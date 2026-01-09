//Given a binary tree. Determine the largest binary search tree size.

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

struct Info
{
    int Size;
    int maxx;
    int minn;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node* root)
{
    if(root == NULL) return {0,INT_MIN, INT_MAX, 0, true};
    if(root->left == NULL && root->right == NULL) return {1,root->data, root->data, 1, true}; //leaf node

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info currInfo;
    currInfo.Size = (leftInfo.Size + rightInfo.Size + 1);

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.maxx < root->data && rightInfo.minn > root->data)
    {
        currInfo.minn = min(leftInfo.minn, min(rightInfo.minn, root->data));
        currInfo.maxx = max(rightInfo.maxx, max(leftInfo.maxx, root->data));
        currInfo.ans = currInfo.Size;
        currInfo.isBST = true;

        return currInfo;
    }

    currInfo.ans = max(leftInfo.ans, rightInfo.ans);
    currInfo.isBST = false;
    return currInfo;
}

int main() {
    /*
          15
        20 30
       5
    */

    Node* root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);

    cout << largestBSTinBT(root).ans << nn;

    return 0;
}



