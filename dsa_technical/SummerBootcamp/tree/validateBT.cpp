#include <iostream>
using namespace std;
class node
{
public:
    node *left;
    int data;
    node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class tree
{
public:
    node *buildTree(node *root, int val)
    {
        if (val == -1)
            return NULL;
        if (root == NULL)
        {
            root = new node(val);
        }
        else
        {
            buildTree(root->left, val);
            buildTree(root->right, val);
        }
        return root;
    }
    // calculating height of tree with the help of nodes not the edges.
    int height(node *root)
    {
        int lh, rh;
        if (root == NULL)
            return 0;

        lh = height(root->left);
        rh = height(root->right);

        return 1 + max(lh, rh);
    }
    // it takes o(n2) time coplexity -- brute force approch
    bool validate(node *root)
    {
        int lh, rh;
        if (root == NULL)
            return true;
        lh = height(root->left);
        rh = height(root->right);
        if (abs(lh - rh) > 1)
            return false;
        bool left = validate(root->left);
        bool right = validate(root->right);

        if (!left || !right)
            return false;
        return true;
    }
};
int main()
{
    node *root = NULL;
    tree t;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = t.buildTree(root, x);
    }
    if (t.validate(root))
        cout << " binary tree is balanced" << endl;
    else
        cout << " binary tree is not balanced" << endl;
    return 0;
}