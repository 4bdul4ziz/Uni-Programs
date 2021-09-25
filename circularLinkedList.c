#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

int main(void)
{
    int choice = -1;
    int element, pos, size;

    Node *first = NULL;

    void addElement(Node * *p, int v);
    void displayElements(Node * p);
    void deleteElement(Node * *p, int v);
    void addAfterElement(Node * *p, int v, int x);
    void listDestructor(Node * *p);

    setbuf(stdout, NULL);

    printf("Enter the choice : \n1 to add\n2 to print\n3 for delete\n4 for add element to first position\n5 for delete list\n");

    do
    {

        printf("Enter Choice\n");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
        {
            //Add an element

            printf("Enter the element\n");
            scanf("%d", &element);

            addElement(&first, element);
            break;
        }
        case 2:
        {
            //Display all elements

            displayElements(first);

            break;
        }
        case 3:
        {
            //Delete Element

            printf("Enter the element\n");
            scanf("%d", &element);

            deleteElement(&first, element);
            break;
        }
        case 4:
        {
            //Add element after certain element

            printf("Enter the element and previous\n");
            scanf("%d%d", &element, &pos);

            addAfterElement(&first, element, pos);

            break;
        }
        default:
        {
            choice = -1;
        }
        }

    } while (choice != -1);

    //listDestructor(&first);
    printf("End");

    return EXIT_SUCCESS;
}

void addElement(Node **p, int v)
{

    Node *newNode = NULL;

    newNode = (Node *)calloc(1, sizeof(Node));
    newNode->data = v;

    if (*p == NULL)
    {
        *p = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = (*p)->next;
        (*p)->next = newNode;
        *p = newNode;
    }
}

void displayElements(Node *p)
{
    Node *temp = p->next;

    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != p->next);
}

void deleteElement(Node **p, int v)
{

    Node *temp = (*p)->next;
    Node *previous = *p;

    int flag = 0;

    do
    {
        if (temp->data == v)
        {
            flag = 1;
            break;
        }

        previous = temp;
        temp = temp->next;
    } while (temp != (*p)->next);

    if (flag == 0)
    {
        printf("The element does not exist, hence cannot be deleted\n");
    }
    else
    {

        //Delete the first element

        if (temp == temp->next)
        {

            *p = NULL;
        }
        else
        {
            //Delete an element at anu pos

            previous->next = temp->next;

            //If last element is tp be deleted

            if (temp == *p)
            {
                *p = previous;
            }
        }

        free(temp);
    }
}

void addAfterElement(Node **p, int v, int x)
{

    Node *newNode, *temp = (*p)->next;
    int flag = 0;

    do
    {
        if (temp->data == x)
        {
            flag = 1;
            break;
        }

        temp = temp->next;
    } while (temp != (*p)->next);

    if (flag == 0)
    {
        printf("The element does not exist, hence cannot be added after it\n");
    }
    else
    {
        newNode = (Node *)calloc(1, sizeof(Node));
        newNode->data = v;

        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == *p)
        {
            *p = newNode;
        }
    }
}

void listDestructor(Node **p)
{

    Node *temp = (*p)->next;

    do
    {
        temp = (*p)->next;

        free(*p);
        (*p) = temp;
    } while (temp != (*p)->next);

    free(p);
}
