#include <stdio.h>
#include <stdlib.h>

struct node *create_list(struct node *start, int n);
void display(struct node *start);
struct node *addatbeg(struct node *start, int data_in);
struct node *addatend(struct node *start, int data_in);
struct node *insert(struct node *head, int value, size_t position);
void Split(struct node *source, struct node *a, struct node *b, int key, int pos);
int llist_exists(struct node *list, int value);
int insert_new_in_sorted(struct node *q, int num);

struct node
{
    int data_in;
    struct node *next;
};

int l = 0;

struct node *create_list(struct node *start, int n)
{
    int i, data_in;

    start = NULL;
    if (n == 0)
        return start;

    printf("\nEnter the element to be inserted : ");
    scanf("%d", &data_in);
    start = addatbeg(start, data_in);

    for (i = 2; i <= n; i++)
    {
        printf("\nEnter the element to be inserted : ");
        scanf("%d", &data_in);
        start = addatend(start, data_in);
    }
    return start;
}

void display(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("Empty\n");
        return;
    }
    p = start;

    while (p != NULL)
    {
        printf("%d ", p->data_in);
        p = p->next;
    }
    printf("\n\n");
}

struct node *addatbeg(struct node *start, int data_in)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data_in = data_in;
    tmp->next = start;
    start = tmp;
    return start;
}

struct node *addatend(struct node *start, int data_in)
{
    struct node *p, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data_in = data_in;
    p = start;
    while (p->next != NULL)
        p = p->next;
    p->next = tmp;
    tmp->next = NULL;
    return start;
}

void sort(struct node **h)
{
    int i, j, a;

    struct node *temp1;
    struct node *temp2;

    for (temp1 = *h; temp1 != NULL; temp1 = temp1->next)
    {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
        {
            if (temp2->data_in < temp1->data_in)
            {
                a = temp1->data_in;
                temp1->data_in = temp2->data_in;
                temp2->data_in = a;
            }
        }
    }
}

int llist_exists(struct node *list, int value)
{

    struct node *e;
    e = list;
    int result = 0;

    while (e != NULL)
    {
        e = e->next;
        if (e->data_in == value)
        {
            printf("The address of the node with data %d is : %d", value, e);
            display(e);
            break;
        }
        }
    return result;
}

int insert_new_in_sorted(struct node *q, int num)
{
    int z = 1;
    while (q != NULL)
    {
        if (q->data_in > num)
            return z;
        q = q->next;
        z++;
    }
}

int main()
{
    struct node *start1 = NULL, *start2 = NULL;

    int n, i_data_in, i_pos, key, counter = 0, arr[20], i = 0;
    printf("Enter number of elements ");
    scanf("%d", &n);
    start1 = create_list(start1, n);
    printf("\nList L1 is :");
    display(start1);

    struct node *a = NULL, *b = NULL;

    printf("Enter the key ");
    scanf("%d", &key);

    while (start1 != NULL)
    {
        arr[i] = start1->data_in;
        start1 = start1->next;
        i++;
    }

    for (i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    counter = llist_exists(start1, key);
    printf("%d", counter);
    // if (counter == 1)
    // {
    //     i_pos = insert_new_in_sorted(start1, key);
    //     printf("\n%d ", i_pos);
    //     // a = addatbeg(a, arr[0]);

    //     // for (i = 1; i <= i_pos; i++)
    //     // {
    //     //     a = addatend(a, arr[i]);
    //     // }

    //     // b = addatbeg(b, arr[i_pos + 1]);

    //     // for (i = 1; i <= i_pos; i++)
    //     // {
    //     //     b = addatend(b, arr[i]);
    //     // }
    //     // printf("Front List: ");
    //     // display(a);

    //     // printf("Back List: ");
    //     // display(b);
    // }
    // else
    //     printf("\nEmpty");

    return 0;
}