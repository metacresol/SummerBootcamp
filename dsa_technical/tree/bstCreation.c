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
void inorder(Tree *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
}
void preorder(Tree *root)
{
    if (root == NULL)
        return;
    printf("%d ->", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Tree *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ->", root->data);
}

Tree *search(Tree *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (root->data > key)
        return search(root->left, key);
    return search(root->right, key);
}
int main()
{
    Tree *root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 30);
    printf("Preorder traversal : ");
    preorder(root);
    printf("\n");
    printf("Inorder traversal : ");
    inorder(root);
    printf("Postorder traversal : ");
    postorder(root);
    Tree *temp = search(root, 10);
    printf("\nkey %d is found", temp->data);
    return 0;
}