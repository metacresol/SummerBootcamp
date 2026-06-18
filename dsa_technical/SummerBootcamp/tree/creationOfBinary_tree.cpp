#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
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
    static int idx;
    node *createTree(int nodes[])
    {

        idx++;
        if (nodes[idx] == -1)
            return NULL;
        node *root = new node(nodes[idx]);
        root->left = createTree(nodes);
        root->right = createTree(nodes);

        return root;
    }
    void preorder(node *root)
    {
        if (root == NULL)
            return;
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
    }
};
int tree::idx = -1;
int main()
{
    tree t;
    int n;
    cin >> n;
    int nodes[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i];
    }
    node *root = t.createTree(nodes);

    cout << "Preorder Traversal: ";
    t.preorder(root);

    return 0;
}