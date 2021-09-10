#include<stdio.h>
#include<stdlib.h>

struct node;
typedef struct Node *List;
typedef struct Node *Position;
Position P;
List L;
int isLast(Position P, List L);
int isEmpty(List L);
Position Find (int X, List L);
void Delete (int X, List L);
Position FindPrev (int X, List L);
Position FindNext (int X, List L);
void insert(int X, List L, Position P);
void DeleteList(List L);
struct Node{
    int Element;
    Position Next;
};


void Insert(int X, List L, Position P){
    Position Newnode = (struct Node *)malloc(sizeof(struct Node));
    if(Newnode != NULL){
        Newnode -> Element = X;
        Newnode -> Next = P -> Next;
        P -> Next = Newnode;
    }
};

int IsEmpty(List L){
    if(L -> Next == NULL)
        return 1;
    else{
        return 0;
    }
}

int isLast(Position P, List L){
    if (P -> Next == NULL)
        return 1;
    
    else{
        return 0;
    }
}

Position node createNode() {
  node Temp;
  Temp = (node)malloc(sizeof(struct LinkedList));
  Temp->Next = NULL;
  return Temp;
}

Position Find(int X, List L){
    Position P;
    P = L -> Next;
    while (P != NULL && P -> Element != X)
        P = P -> Next;
    return P;
};

Position FindPrev(int X, List L){
    Position P;
    P = L;
    while (P -> Next != NULL && P -> Next -> Element != X)
        P = P -> Next;
    return P;
};

Position FindNext(int X, List L){
    P = L -> Next;
    while (P -> Next != NULL && P -> Element != X)
        P = P -> Next;
    return P -> Next;
};

void Delete (int X, List L){
    Position P, Temp;
    P = FindPrev(X, L);
    if(! isLast(P,L)){
        Temp = P -> Next;
        P -> Next = Temp -> Next;
        free(Temp);
    }
};

void DeleteList (List L){
    Position P, Temp;
    P = L -> Next;
    L -> Next = NULL;
    while (P!=NULL){
        Temp = P -> Next;
        free(P);
        P = Temp;
    }
};

int Count()
{
    int Count = 0;
    Position P, Temp;
    while (Temp != 0)
    {
        Count++;
        Temp = Temp->Next;
    }
    printf("\nNo Of Items In Linked List : %d\n", Count);
    return Count;
};

void Display(List L) {
  printf("\n");
  Position P = L;
  while (P != NULL) {
    printf("%d ", P->Element);
    P = P->Next;
  }
  printf("\n");
}

int main() {
  // Declaring List with Head
  List List1;

  //IsEmpty
  IsEmpty(List1);
  List1 = createNode();
  printf("\nInitialising\n");
  List1->data=10;
  Display(List1);

  // Inserting
  node first = insert(List1, 15);
  Display(List1);
  node second = insert(List1, 22);
  Display(List1);

  // Deleting
  Delete (List1->Next, List1);
  Display(List1);

  // FindnNext
  FindNext(15, List1);

  //Islast
  printf("\nChecking Node Second :\n");
  isLast(second);
  printf("\n");

  //Find
  Find(22,List1);

}
