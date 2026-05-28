// cases in deletion
//  1st-- deleting a leaf node.
//  2nd--deleting a node having 1 child.
//  3rd---deleting a node having 2 child.
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Tree;
Tree *createNode(int x)
{
    Tree *node = (Tree *)malloc(sizeof(Tree));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Tree *insert(Tree *root, int x)
{
    if (root == NULL)
        return createNode(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}
Tree *searchMax(Tree *root)
{
    if (root == NULL)
        return root;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
Tree *delete(Tree *root, int key)
{
    // from line 43 to 49 is code for traversal and searching for key.
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->left, key);
    else
    {
        if (root->left == NULL)
        {
            Tree *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Tree *temp = root->left;
            free(root);
            return temp;
        }
        Tree *temp = searchMax(root->right);
        root->data = temp->data;
        root->right = delete(root->right, key);
        free(temp);
    }
    return root;
}
void inorder(Tree *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
}
int main()
{
    Tree *root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 30);
    Tree *temp = delete(root, 10);
    // printf("%d is deleted from tree", temp->data);
    inorder(temp);
    return 0;
}