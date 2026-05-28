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

int searchMIN(Tree *root)
{
    if (root == NULL)
        return -1;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
int searchMax(Tree *root)
{
    if (root == NULL)
        return -1;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int main()
{
    Tree *root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 30);
    printf("\nMinimum element is  %d", searchMIN(root));
    printf("\nMaximum element is  %d", searchMax(root));
    return 0;
}