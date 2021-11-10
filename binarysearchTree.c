#include <stdio.h>
#include <stdlib.h>
struct node
{
    int D;
    char character;
    struct node *left, *right;
};
// creation of root
char c = 'A';
struct node *newNode(int N)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->D = N;
    temp->character = c++;
    temp->left = temp->right = NULL;
    return temp;
}
struct node *insert(struct node *node, int D)
{
    if (node == NULL)
        return newNode(D);
    if (D <= node->D)
        node->left = insert(node->left, D);
    else if (D > node->D)
        node->right = insert(node->right, D);
    return node;
}
// end of creation of root
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%c", root->character);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%c", root->character);
    inorder(root->left);
    inorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    inorder(root->right);
    printf("%c", root->character);
}
int temp = 0;
int height(struct node **root)
{
    int h1, h2;
    if (*root == NULL)
    {
        return -1;
    }
    h1 = height((&(*root)->left)) + 1;
    h2 = height((&(*root)->right)) + 1;
    return h1 > h2 ? h1 : h2;
}
void search(struct node *root, int N)
{
    if (root == NULL)
    {
        printf("NOt found");
        return;
    }
    if (root->D == N)
    {
        printf("Found");
        return;
    }
    if (root->D < N)
    {
        search(root->right, N);
        return;
    }
    search(root->left, N);
    return;
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 100);
    insert(root, 120);
    insert(root, 10);
    printf("The In_order is : ");
    inorder(root);
    printf("\n");
    printf("The pre_order is : ");
    preorder(root);
    printf("\n");
    printf("The post_order is : ");
    postorder(root);
    printf("\nThe height of the root is: %d\n", height(&root));
    search(root, 60);
    return 0;
}