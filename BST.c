#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
struct node
{
    int key;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d -> ", root->key);
        inorder(root->right);
    }
}
struct node *search(struct node *root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int main()
{
    struct node *root = NULL;
    struct node *temp = NULL;

    int choice, e, e1, e2;
    char ans;
    for (int i = 0; i < 20; i++)
    {
        root = insert(root, i);
    }
    do
    {
        printf("\n\n1.Enter More Nodes");
        printf("\n2.Delete A Node");
        printf("\n3.Search For A Node");
        printf("\n4.Exit");
        printf("\nEnter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            do
            {
                printf("Enter An Element:");
                scanf("%d", &e);
                root = insert(root, e);
                printf("\nEnter More Elements(y/n)\n");
                ans = getch();
            } while (ans == 'y');
            break;
        case 2:
            printf("Enter An Element to be deleted:");
            scanf("%d", &e1);
            root = deleteNode(root, e1);
            printf("%d has been deleted", e1);
            break;
        case 3:
            printf("Enter An Element to be searched for:");
            scanf("%d", &e2);
            temp = search(root, e2);
            if (temp != NULL)
            {
                printf("Element Was Found\n");
            }
            else
            {
                printf("Element Was Not Found\n");
            }
        }
    } while (choice != 4);
}