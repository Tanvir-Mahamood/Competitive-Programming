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

Node* InsertBST(Node *root, int val)
{
    if(root == NULL) return new Node(val);

    if(val < root->data) root->left = InsertBST(root->left, val);
    else  root->right = InsertBST(root->right, val);

    return root;
}

void inorder(Node *root)
{
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* SearchBST(Node* root, int key)
{
    if(root == NULL) return NULL;

    if(root->data == key) return root;
    if(root->data > key) return SearchBST(root->left, key);
    return SearchBST(root->right, key);
} //O(lgn)

Node* inorderSucc(Node* root)
{
    Node* curr = root;
    while(curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node* DeleteBST(Node* root, int key)
{
    if(key < root->data) root->left = DeleteBST(root->left, key);
    else if(key > root->data) root->right = DeleteBST(root->right, key);
    else
    {
        if(root->left == NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = DeleteBST(root->right, temp->data);
    }
    return root;
}

//Check for BST
bool isBST(Node* root, Node* minn=NULL, Node* maxx=NULL)
{
    if(root == NULL) return true;

    if(minn != NULL && root->data <= minn->data) return false;
    if(maxx != NULL && root->data >= maxx->data) return false;

    bool leftValid = isBST(root->left, minn, root);
    bool rightValid = isBST(root->right, root, maxx);

    return (leftValid and rightValid);
} //O(n)

void zigzagTraversal(Node* root)
{
    if(root == NULL) return;

    stack<Node*> currLevel, nextLevel;

    bool LeftToRight = true;

    currLevel.push(root);
    while(!currLevel.empty())
    {
        Node* temp = currLevel.top();
        currLevel.pop();

        if(temp != NULL)
        {
            cout << temp->data << " ";

            if(LeftToRight)
            {
                if(temp->left) nextLevel.push(temp->left);
                if(temp->right) nextLevel.push(temp->right);
            }
            else
            {
                if(temp->right) nextLevel.push(temp->right);
                if(temp->left) nextLevel.push(temp->left);
            }
        }
        if(currLevel.empty())
        {
            LeftToRight = !LeftToRight;
            swap(currLevel, nextLevel);
        }
    }
} // O(n)

void solve()
{
    Node *root = NULL;
    root = InsertBST(root, 5);
    //InsertBST(root, 5);
    InsertBST(root, 1);
    InsertBST(root, 3);
    InsertBST(root, 3);
    InsertBST(root, 2);
    InsertBST(root, 7);

    // if we apply inorder traversal to a Binary Search Tree, we find a sorted sequence
    inorder(root); cout << nn;

    zigzagTraversal(root); cout << nn;

    // Search in a BST
    (SearchBST(root, 6) == NULL) ? cout << "Key does not exist\n" : cout << "Key exists\n";

    // Delete in a BST
    //DeleteBST(root, 1);
    //inorder(root);

    (isBST(root, NULL, NULL)) ? cout << "Valid BST\n" : cout << "Invalid BST\n";
}

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    for(int i=1; i<=t; i++)
    {
        //cout << "Case " << i << ": \n";
        solve();
    }

    return 0;
}



