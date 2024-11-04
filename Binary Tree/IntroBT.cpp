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

void preorder(struct Node* root)
{
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root)
{
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(struct Node* root)
{
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(struct Node* root)
{
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if(node != NULL)
        {
            cout << node->data << " ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }
}

int sumAK(struct Node* root, int k) // sum of nodes at k level
{
    if(root == NULL) return -1;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    int level = 0, sum = 0;

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if(node != NULL)
        {
            if(level == k)
            {
                sum += node->data;
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int countNodes(Node* root) // count total number of roots
{
    if(root == NULL) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumNodes(Node* root) // sum of all nodes
{
    if(root == NULL) return 0;
    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

int calcHeight(Node* root) // calculate height of BT
{
    if(root == NULL) return 0;
    int lheight = calcHeight(root->left);
    int rheight = calcHeight(root->right);
    return max(lheight, rheight) + 1;
} // O(n); n = number of all nodes

int calcDiameter(Node* root) // calculate diameter of BT
{
    if(root == NULL) return 0;

    int lheight = calcHeight(root->left);
    int rheight = calcHeight(root->right);
    int currentDiameter1 = lheight + rheight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);
    int currentDiameter2 = max(lDiameter, rDiameter);

    return max(currentDiameter1, currentDiameter2);
} // O(n^2); n = number of all nodes

int calcDiameterOptimised(Node* root, int* height)
{
    if(root == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;

    int ldiameter = calcDiameterOptimised(root->left, &lh);
    int rdiameter = calcDiameterOptimised(root->right, &rh);
    int currdiameter1 = max(ldiameter, rdiameter);

    int currdiameter2 = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currdiameter1, currdiameter2);
} // O(n); n = number of all nodes


    /*
       1
      / \
     2   3
    / \ / \
   4  5 6  7

   After transformation:

       28
      / \
     11  16
    / \ / \
   4  5 6  7

    */
void sumReplace(Node* root)
{
    if(root == NULL) return;

    sumReplace(root->left);
    sumReplace(root->right);

    if(root->left != NULL)  root->data += root->left->data;
    if(root->right != NULL) root->data += root->right->data;
} // O(n), n = no. of nodes

bool isBalanced(Node* root)
{
    if(root == NULL) return true;

    if(isBalanced(root->left) == false) return false;
    if(isBalanced(root->right) == false) return false;

    int lh = calcHeight(root->left);
    int rh = calcHeight(root->right);

    if(abs(lh - rh) <= 1) return true;
    else return false;
} // O(n^2)

bool isBalancedOptimised(Node* root, int* height)
{
    if(root == NULL) return true;

    int lh = 0, rh = 0;

    if(isBalancedOptimised(root->left, &lh) == false) return false;
    if(isBalancedOptimised(root->right, &rh) == false) return false;

    *height = max(lh, rh) + 1;

    if(abs(lh-rh) <= 1) return true;
    else return false;
} // O(n)


void rightView(Node* root)
{
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        for(int i=0; i<n; i++)
        {
            Node* curr = q.front();
            q.pop();

            if(i == n-1) cout << curr->data << " ";

            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }
    }
} // O(n)

void leftView(Node* root)
{
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        for(int i=0; i<n; i++)
        {
            Node* curr = q.front();
            q.pop();

            if(i == 0) cout << curr->data << " ";

            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }
    }
} // O(n)

// To determine distance between 2 nodes using LCA
Node* LCA(Node* root, int n1, int n2)
{
    if(root == NULL) return NULL;
    if(root->data == n1 || root->data == n2) return root;

    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if(left != NULL && right != NULL) return root;
    if(left == NULL && right == NULL) return NULL;
    if(left != NULL) return LCA(root->left, n1, n2);
    return LCA(root->right, n1, n2);
}
int findDist(Node* root, int k, int dist)
{
    if(root == NULL) return -1;
    if(root->data == k) return dist;

    int left = findDist(root->left, k, dist+1);
    if(left != -1) return left;
    return findDist(root->right, k, dist+1);
}
int distanceNodes(Node* root, int n1, int n2)
{
    Node* lca = LCA(root, n1, n2);
    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);
    return (d1 + d2);
}

// Flatten a BT
void flatten(Node* root)
{
    if(root == NULL || root->left == NULL && root->right == NULL) return;

    if(root->left != NULL)
    {
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while(t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;
    }
    flatten(root->right);
}

// Print all nodes at distance k
// case 1:search in subtree
void printSubtreeNodes(Node* root, int k)
{
    if(root == NULL || k < 0) return;
    if(k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printSubtreeNodes(root->left, k-1);
    printSubtreeNodes(root->right, k-1);
}
// case 2: search in ancestor
int printNodesAtk(Node* root, Node* target, int k)
{
    if(root == NULL) return -1;
    if(root == target)
    {
        printSubtreeNodes(root, k);
        return 0;
    }

    int dl = printNodesAtk(root->left, target, k);
    if(dl != -1)
    {
        if(dl + 1 == k) cout << root->data << " ";
        else printSubtreeNodes(root->right, k-dl-2);
    }
    return 1+dl;

    int dr = printNodesAtk(root->right, target, k);
    if(dr != -1)
    {
        if(dr + 1 == k) cout << root->data << " ";
        else printSubtreeNodes(root->left, k-dr-2);
    }
    return 1+dr;


    return -1;
}

bool getpath(Node* root, int key, vector<int> &path)
{
    if(root == NULL) return false;
    path.push_back(root->data);
    if(root->data == key) return true;
    if(getpath(root->left, key, path) || getpath(root->right, key, path)) return true;
    path.pop_back();
    return false;
}
int LCA2(Node* root, int n1, int n2)
{
    vector<int> path1, path2;

    if(!getpath(root, n1, path1) || !getpath(root, n2, path2)) return -1;

    int pc;
    for(pc=0; pc<path1.size() && path2.size() ; pc++)
    {
        if(path1[pc] != path2[pc])
        {
            break;
        }
    }
    return path1[pc-1];
}
Node* LCA3(Node* root, int n1, int n2)
{
    if(root == NULL) return NULL;

    if(root->data == n1 || root->data == n2) return root;

    Node* leftLCA = LCA3(root->left, n2, n1);
    Node* rightLCA = LCA3(root->right, n2, n1);

    if(leftLCA && rightLCA) return root;
    if(leftLCA != NULL) return leftLCA;
    return rightLCA;
}

void solve()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*
       1
      / \
     2   3
    / \ / \
   4  5 6  7

    */

    preorder(root); cout << nn;
    inorder(root); cout << nn;
    postorder(root); cout << nn;
    levelorder(root); cout << nn;

    cout << sumAK(root, 2) << nn; // sum of nodes at k level
    cout << countNodes(root) << nn; // count total number of roots
    cout << sumNodes(root) << nn; // sum of all nodes
    cout << calcHeight(root) << nn; // calculate height of BT
    cout << calcDiameter(root) << nn; // calculate diameter of BT
    int height = 0;
    cout << calcDiameterOptimised(root, &height) << nn; // calculate diameter of BT

    //preorder(root); cout << nn;
    //sumReplace(root);
    //preorder(root); cout << nn;

    /*
    Balanced Height tree:
    For each node, the difference between the heights of the
    left subtree & right subtree <= 1
    |left height - right heoght| <= 1
    */
    (isBalanced(root)) ? cout << "Balanced\n" : cout << "Not balanced";
    height = 0;
    (isBalancedOptimised(root, &height)) ? cout << "Balanced\n" : cout << "Not balanced";

    rightView(root); cout << nn;
    leftView(root); cout << nn;

    cout << distanceNodes(root, 2, 7) << nn;

    /*
    Given a binary tree. Flatten it into linked list inplace. After flattening, left of each
    node should point to NULL and right should contain next node in preorder sequence.
    Its not allowed to use other data structures.
    */
    //flatten(root);
    //inorder(root); cout << nn;
    printNodesAtk(root, root->left, 1); cout << nn;

    Node* ans = LCA(root, 5, 7);
    (ans == NULL) ? cout << "No LCA\n" : cout << ans->data << nn;

    int ans2 = LCA2(root, 5, 7);
    (ans2 == -1) ? cout << "No LCA\n" : cout << ans2 << nn;

    Node* ans3 = LCA3(root, 5, 7);
    (ans3 == NULL) ? cout << "No LCA\n" : cout << ans3->data << nn;
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



