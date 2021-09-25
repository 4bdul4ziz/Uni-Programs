typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} NODE;

void create_list(NODE **start);
void display(NODE *start);
void count(NODE *start);
void search(NODE *start, int data);
void addatbeg(NODE **start, int data);
void addatend(NODE **start, int data);
void addafter(NODE **start, int data, int item);
void addbefore(NODE **start, int data, int item);
void addatpos(NODE **start, int data, int pos);
void del(NODE **start, int data);
void destroy_list(NODE **head);
NODE *reverse(NODE *start);