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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointers(Node* root, Node** first, Node** mid, Node** last, Node** prev)
{
    if(root == NULL) return;

    calcPointers(root->left, first, mid, last, prev);

    if(*prev && root->data < (*prev)->data)
    {
        if(!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcPointers(root->right, first, mid, last, prev);
}

void restoreBST(Node* root)
{
    Node *first, *mid, *last, *prev;
    first = mid = last = prev = NULL;

    calcPointers(root, &first, &mid, &last, &prev);

    if(first && last) swap(&(first->data) , &(last->data));
    else if(first && mid) swap(&(first->data) , &(mid->data));
}

void inorder(Node *root)
{
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    /*
        6
       / \
      3   9
     / \   \
    1   4   13

        6
       / \
      9   3
     / \   \
    1   4   13

    */

    Node* root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);

    inorder(root); cout << nn;
    restoreBST(root);
    inorder(root); cout << nn;

    return 0;
}



