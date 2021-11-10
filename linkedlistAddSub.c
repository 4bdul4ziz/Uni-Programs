#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
struct poly
{
    int c, e;
    struct poly *next;
};
struct poly *read_poly(struct poly *header)
{
    struct poly *p, *temp;
    char ch;
    printf("\nAbdul Aziz A.B - 20BRS1185");
    printf("\nPress Y to create a node, N to exit: ");
    scanf("%c", &ch);
    header->c = NULL;
    header->e = NULL;
    header->next = NULL;
    while (ch != 'n')
    {
        p = (struct poly *)malloc(sizeof(struct poly));
        printf("\nCoefficient value : ");
        scanf("%d", &p->c);
        printf("\nExponential value : ");
        scanf("%d", &p->e);
        p->next = NULL;
        if (header->next == NULL)
        {
            header->next = p;
            temp = p;
        }
        else
        {
            temp->next = p;
            temp = p;
        }
        printf("\nEnter Y to create a new node, N to exit: ");
        getchar();
        scanf("%c", &ch);
    }
    return header;
}
struct poly *poly_add(struct poly *p, struct poly *q, struct poly *r)
{
    p = p->next;
    q = q->next;
    struct poly *newnode, *temp;
    r->next = NULL;
    while ((p != NULL) && (q != NULL))
    {
        newnode = (struct poly *)malloc(sizeof(struct poly));
        newnode->next = NULL;
        if (p->e == q->e)
        {
            newnode->c = p->c + q->c;
            newnode->e = p->e;
            p = p->next;
            q = q->next;
        }
        else if (p->e > q->e)
        {
            newnode->c = p->c;
            newnode->e = p->e;
            p = p->next;
        }
        else
        {
            newnode->c = q->c;
            newnode->e = q->e;
            q = q->next;
        }
        if (r->next == NULL)
        {
            r->next = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    if (p != NULL)
    {
        while (p != NULL)
        {
            newnode = (struct poly *)malloc(sizeof(struct poly));
            newnode->next = NULL;
            newnode->c = p->c;
            newnode->e = p->e;
            temp->next = newnode;
            temp = newnode;
            p = p->next;
        }
    }
    if (q != NULL)
    {
        while (q != NULL)
        {
            newnode = (struct poly *)malloc(sizeof(struct poly));
            newnode->next = NULL;
            newnode->c = q->c;
            newnode->e = q->e;
            temp->next = newnode;
            temp = newnode;
            q = q->next;
        }
    }
}
struct poly *poly_sub(struct poly *p, struct poly *q, struct poly *r)
{
    p = p->next;
    q = q->next;
    struct poly *newnode, *temp;
    r->next = NULL;
    while ((p != NULL) && (q != NULL))
    {
        newnode = (struct poly *)malloc(sizeof(struct poly));
        newnode->next = NULL;
        if (p->e == q->e)
        {
            newnode->c = p->c - q->c;
            newnode->e = p->e;
            p = p->next;
            q = q->next;
        }
        else if (p->e > q->e)
        {
            newnode->c = p->c;
            newnode->e = p->e;
            p = p->next;
        }
        else
        {
            newnode->c = q->c;
            newnode->e = q->e;
            q = q->next;
        }
        if (r->next == NULL)
        {
            r->next = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    if (p != NULL)
    {
        while (p != NULL)
        {
            newnode = (struct poly *)malloc(sizeof(struct poly));
            newnode->next = NULL;
            newnode->c = p->c;
            newnode->e = p->e;
            temp->next = newnode;
            temp = newnode;
            p = p->next;
        }
    }
    if (q != NULL)
    {
        while (q != NULL)
        {
            newnode = (struct poly *)malloc(sizeof(struct poly));
            newnode->next = NULL;
            newnode->c = q->c;
            newnode->e = q->e;
            temp->next = newnode;
            temp = newnode;
            q = q->next;
        }
    }
}
void traverse(struct poly *header)
{
    struct poly *ptr = header->next;
    while (ptr != NULL)
    {
        printf(" %dx^%d", ptr->c, ptr->e);
        ptr = ptr->next;
    }
}
int main()
{
    int ch;
    struct poly *p, *q, *r;
    p = (struct poly *)malloc(sizeof(struct poly));
    q = (struct poly *)malloc(sizeof(struct poly));
    r = (struct poly *)malloc(sizeof(struct poly));
    printf("\n Enter polynomial P : ");
    p = read_poly(p);
    traverse(p);
    printf("\n Enter polynomial Q : ");
    getchar();
    q = read_poly(q);
    traverse(q);
    do
    {
        printf("\n\n Abdul Aziz A.B - 20BRS1185 - Exp: 8 - MENU ");
        printf("\n 1.Polynomial Addition ");
        printf("\n 2.Polynomial Subtraction ");
        printf("\n 3.Exit ");
        printf("\n Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            poly_add(p, q, r);
            traverse(r);
            break;
        case 2:
            poly_sub(p, q, r);
            traverse(r);
            break;
        case 3:
            exit(0);
        default:
            printf("Error!\n");
            break;
        }
    } while (ch != 4);
    getchar();
}
