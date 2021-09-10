#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
  int data;
  struct LinkedList *next;
};

typedef struct LinkedList *node;
typedef struct LinkedList *List;
typedef struct LinkedList *Position;

node createNode() {
  node temp;
  temp = (node)malloc(sizeof(struct LinkedList));
  temp->next = NULL;
  return temp;
}

node insert(node n1, int value) {
  node temp;
  temp = createNode();
  temp->data = value;

  if (n1 == NULL) {
    n1 = temp;
    printf("\nEmpty\n");
  } else {
    printf("\nInserting\n");
    temp->next = n1->next;
    n1->next = temp;
    }
  return temp;
}

node findPrev(node n1, node head) {
  Position p;
  p = head;
  while (p->next != NULL) {
    if (p->next == n1) {
      printf("The previous node is: %d", p->data);
      return p;
      break;
    }
    else{
        printf("No previous node is available to display.");
    }
  }
}

node findNext(node n1) {
  node nxt = n1->next;
  printf("The next node is: %d", nxt->data);
  return nxt;
}

void delete (node n1, node head) {
  printf("\nDeleting the element... Done.\n");
  node temp;
  temp = findPrev(n1, head);

  temp->next = n1->next;
}

void isEmpty(node head) {
  if (head == NULL) {
    printf("The List is Empty\n");
  }
  else{
      printf("The List is not empty.\n");
  }
}

void isLast(node n1) {
  if (n1->next == NULL) {
    printf("The node Last in the List is :");
  }
  else{
      printf("The node is not the Last node");
  }
}

void Display_Node(node n1) {
  printf("\nNode Value :%d\n", n1->data);
  printf("Node Next :%p", n1->next);
  printf("\n");
}

void Find(int X,node head)
{
    Position p = head;
    while(p!=NULL)
    {
        p = p->next;
        if (p->data == X)
        {
            printf("The address of the node with data %d is : %d",X, p);
            Display_Node(p);
            break;
        }
        else
        {
            printf("The node is either deleted or not valid.");
        }
    }
}


void Display(List L) {
  printf("\n");
  Position P = L;
  while (P != NULL) {
    printf("%d ", P->data);
    P = P->next;
  }
  printf("\n");
}

void Delete_List(List L)
{
    Position p,temp;
    p = L -> next;
    L -> next = NULL;
    while(p!=NULL)
    {
        temp = p-> next;
        free(p);
        p = temp;
        printf("The list was deleted successfully.");
    }
}

int main() {
  // Declaring List with Head

  //IsEmpty
  isEmpty(NULL);
  
  List List1;
  List1 = createNode();
  printf("\nInitialising\n");
  //IsEmpty
  isEmpty(List1);
  
  List1->data=10;
  Display(List1);

  // Inserting
  node first = insert(List1, 15);
  Display(List1);
  node second = insert(List1, 22);
  Display(List1);

  // Deleting
  //delete (List1->next, List1);
  //Display(List1);

  // FindNext
  // findNext(second);

  // FindPrev
  //findPrev(second, first);

  //Islast
  //printf("\n Checking if the second node is the last node - :\n");
  //isLast(second);
  //printf("\n");

  //Find
  //Find(15,List1);
  
  //Delete_List
  //Delete_List(List1);
}
