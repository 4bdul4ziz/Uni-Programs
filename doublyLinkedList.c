#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
typedef struct node list;
void opr();
list *create_node();
list *insert(list *);
list *insertatbeg(list *);
list *insertatend(list *);
list *insertatpos(list *);
void traverse(list *);
int length(list *);
int search(list *);
void sort(list *);
list *reverse(list *);
list *delete (list *);
list *deleteatbeg(list *);
list *deleteatend(list *);
list *deleteatpos(list *);
int main()
{
    opr();
    return 0;
}
void opr()
{
    list *start = NULL;
    int c = 1, len = 0, flag = 0;
    while (c != 0)
    {
        printf("\n			************MENU************\n1.Insert\n2.Delete\n3.Length\n4.Search\n5.Sort\n6.Reverse\n7.Traverse\n0.Exit\nEnter the Operation:- ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            start = insert(start);
            break;
        case 2:
            start = delete (start);
            break;
        case 3:
            len = length(start);
            printf("The Length of Doubly Linked List is %d.\n", len);
            break;
        case 4:
            flag = search(start);
            if (flag == 0)
                printf("\nElement Not Found.\n");
            break;
        case 5:
            sort(start);
            traverse(start);
            break;
        case 6:
            start = reverse(start);
            traverse(start);
            break;
        case 7:
            traverse(start);
            break;
        case 0:
            printf("\n			***********EXIT***********\n");
            exit(0);
        }
    }
}
list *create_node()
{
    list *q;
    q = (list *)malloc(sizeof(list));
    if (q == NULL)
        printf("\nNode Not Created.\n");
    else
        printf("\nNode Created.\n");
    return (q);
}
list *insert(list *start)
{
    int c;
    if (length(start) == 0)
    {
        start = insertatbeg(start);
        traverse(start);
        return (start);
    }
    printf("\n1.Insertion at Beginning\n2.Insertion at Ending\n3.Insertion at Position\n4.Menu\n0.Exit\nEnter the Operation:- ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        start = insertatbeg(start);
        traverse(start);
        break;
    case 2:
        start = insertatend(start);
        traverse(start);
        break;
    case 3:
        start = insertatpos(start);
        traverse(start);
        break;
    case 4:
        opr();
        break;
    case 0:
        printf("\n			***********EXIT***********\n");
        exit(0);
    default:
        printf("\nInvalid Choice.\n");
        insert(start);
    }
    return (start);
}
list *insertatbeg(list *start)
{
    list *newnode;
    newnode = create_node();
    if (newnode == NULL)
        return (start);
    printf("\nEnter the Value of the Node:- ");
    scanf("%d", &newnode->data);
    if (start == NULL)
        newnode->left = newnode->right = NULL;
    else
    {
        newnode->left = NULL;
        newnode->right = start;
        start->left = newnode;
    }
    start = newnode;
    return (start);
}
list *insertatend(list *start)
{
    list *temp = start, *newnode;
    newnode = create_node();
    if (newnode == NULL)
        return (start);
    printf("\nEnter the value:- ");
    scanf("%d", &newnode->data);
    while (temp->right != NULL)
        temp = temp->right;
    temp->right = newnode;
    newnode->left = temp;
    newnode->right = NULL;
    return (start);
}
list *insertatpos(list *start)
{
    int pos, i;
    if (length(start) == 0)
    {
        start = insertatbeg(start);
        return (start);
    }
    printf("\nEnter the Position:- ");
    scanf("%d", &pos);
    if (pos > length(start) + 1)
    {
        printf("\nPosition Not Possible.\n");
        start = insertatpos(start);
    }
    else if (pos == 1)
        start = insertatbeg(start);
    else
    {
        list *temp = start, *newnode;
        newnode = create_node();
        if (newnode == NULL)
            return (start);
        printf("\nEnter the value:- ");
        scanf("%d", &newnode->data);
        for (i = 1; i < pos - 1; i++)
            temp = temp->right;
        newnode->right = temp->right;
        newnode->left = temp;
        temp->right = newnode;
    }
    return (start);
}
void traverse(list *start)
{
    list *temp = start;
    if (start == NULL)
    {
        printf("\nNo Element to Print.\n");
        return;
    }
    while (temp != NULL)
    {
        printf(" [%lu]%d[%lu] ", temp->left, temp->data, temp->right);
        temp = temp->right;
    }
}
int length(list *start)
{
    int len = 0;
    list *temp = start;
    while (temp != NULL)
    {
        temp = temp->right;
        len++;
    }
    return (len);
}
int search(list *start)
{
    int flag = 0, key;
    list *temp = start;
    if (start == NULL)
    {
        printf("\nNo Element to Search.\n");
        return (1);
    }
    printf("\nEnter Element to Search:-");
    scanf("%d", &key);
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("\nElement Found.\n");
            flag = 1;
            break;
        }
        temp = temp->right;
    }
}
void sort(list *start)
{
    int t;
    list *temp1, *temp2, *temp = start;
    for (temp1 = start; temp1 != NULL; temp1 = temp1->right)
    {
        for (temp2 = start; temp2 != NULL; temp2 = temp2->right)
        {
            if (temp1->data < temp2->data)
            {
                t = temp1->data;
                temp1->data = temp2->data;
                temp2->data = t;
            }
        }
    }
}
list *reverse(list *start)
{
    list *prev = NULL;
    list *current = start;
    list *next = NULL;
    while (current != NULL)
    {
        next = current->right;
        current->right = prev;
        prev = current;
        current = next;
    }
    start = prev;
    return (start);
}
list *delete (list *start)
{
    int c;
    if (length(start) == 0)
    {
        printf("\nDeletion Not Possible.\n");
        return (start);
    }
    else if (length(start) == 1)
    {
        free(start);
        printf("\nElement Deleted.\n");
        return (start);
    }
    printf("\n1.Deletion at Beginning\n2.Deletion at Ending\n3.Deletion at Position\n4.Menu\n0.Exit\nEnter the Operation:- ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        start = deleteatbeg(start);
        traverse(start);
        break;
    case 2:
        start = deleteatend(start);
        traverse(start);
        break;
    case 3:
        start = deleteatpos(start);
        traverse(start);
        break;
    case 4:
        opr();
        break;
    case 0:
        printf("\n			***********EXIT***********\n");
        exit(0);
    default:
        printf("\nInvalid Choice.\n");
        delete (start);
    }
    printf("\nElement Deleted.\n");
    return (start);
}
list *deleteatbeg(list *start)
{
    list *temp = start;
    free(start);
    start = temp->right;
    start->left = NULL;
    return (start);
}
list *deleteatend(list *start)
{
    list *temp = start;
    while (temp->right != NULL)
        temp = temp->right;
    temp->left->right = NULL;
    free(temp);
    return (start);
}
list *deleteatpos(list *start)
{
    int pos, i;
    list *temp = start, *temp2;
    printf("\nEnter the Position:- ");
    scanf("%d", &pos);
    if (pos > length(start))
    {
        printf("\nEnter Valid Position.\n");
        start = deleteatpos(start);
        return (start);
    }
    else if (pos == length(start))
    {
        start = deleteatend(start);
        return (start);
    }
    else if (pos == 1)
    {
        start = deleteatbeg(start);
        return (start);
    }
    for (i = 1; i < pos - 1; i++)
        temp = temp->right;
    temp2 = temp->right;
    temp->right = temp->right->right;
    temp->right->left = temp;
    free(temp2);
    return (start);
}