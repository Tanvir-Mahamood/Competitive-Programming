// Given 2 BST, determine if they are same or not.
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

bool isIdentical(Node* root1, Node* root2)
{
    if(root1 == NULL && root2 == NULL) return true;
    else if(root1 == NULL || root2 == NULL) return false;
    else
    {
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);

        if(cond1 && cond2 && cond3) return true;
        return false;
    }
}

int main() {
    /*
     2
    1 3
    */
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);

    Node* root2 = new Node(6);
    root2->left = new Node(3);
    root2->right = new Node(10);

    (isIdentical(root1, root2)) ? yes : no;

    return 0;
}




