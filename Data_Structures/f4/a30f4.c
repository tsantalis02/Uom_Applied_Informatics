#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NumberOfNodes 10
#define StackLimit 11
#define NilValue -1

typedef struct{
    float bathmos;
    int am;
} ListElementType;

typedef int ListPointer;

typedef int StackElementType;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

typedef struct{
 int Top;
 StackElementType Element[StackLimit];
}StackType;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void TraverseLinked(ListPointer List, NodeType Node[]);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
float FindMins(ListPointer List,NodeType Node[],StackType *Stack);
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
boolean FullStack(StackType Stack);
void TraverseStack(StackType Stack);

int main(){
 NodeType N[NumberOfNodes];
 ListPointer ptr,L,i,pred;
 ListElementType Item;
 StackElementType x;
 StackType S;
 float min;

  InitializeStoragePool(N,&ptr);
  CreateList(&L);
  printf("---------Question C-----------\n");
  printf("---------Storage pool---------\n");
  printAll(L,ptr,N);
  printf("---------Question D-----------\n");
  printf("---------Linked list----------\n");
  TraverseLinked(L,N);
  printf("---------Question E-----------\n");
  for(i=0;i<5;i++){
    printf("DWSE AM GIA EISAGWGH STH LISTA: ");
    scanf("%d",&Item.am);
    printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
    scanf("%f",&Item.bathmos);
    pred=NilValue;
    Insert(&L,N,&ptr,pred,Item);
  }
  printf("---------Question F-----------\n");
  printf("---------Storage pool---------\n");
  printAll(L,ptr,N);
  printf("---------Question G-----------\n");
  printf("---------Linked list----------\n");
  TraverseLinked(L,N);
  printf("---------Question H-----------\n");
    if(EmptyList(L)){
        printf("Empty List\n");
    }else{
        printf("Not an Empty List\n");
    }
  printf("---------Question I-----------\n");
       if(FullList(ptr)){
            printf("Full List\n");
       }else{
            printf("Not a Full List\n");
       }
  min=FindMins(L,N,&S);
  printf("---------Question J------------\n");
  printf("Min value=%.1f\n",min);
  printf("AM with min grade are: ");
  while(!EmptyStack(S)){
    Pop(&S,&x);
    printf(" %d",x);
    }
  printf("\n");
  printf("---------Question K------------\n");
  TraverseStack(S);
  printf("---------Question L------------\n");
  printf("---------Storage pool----------\n");
  printAll(L,ptr,N);
  printf("---------Question M------------\n");
  TraverseLinked(L,N);
return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.am=-1;
        Node[i].Data.bathmos=-1.0;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.am=-1;
    Node[NumberOfNodes-1].Data.bathmos=-1.0;
    *FreePtr=0;
}

void CreateList(ListPointer *List)

{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}


void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data.am =Item.am;
        Node[TempPtr].Data.bathmos=Item.bathmos;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data.am =Item.am;
        Node[TempPtr].Data.bathmos=Item.bathmos;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}


void TraverseLinked(ListPointer List, NodeType Node[])
{


  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d:<%d,%.1f> ->%d) ",CurrPtr,Node[CurrPtr].Data.am,Node[CurrPtr].Data.bathmos ,Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:<%d,%.1f> ->%d) ",i,Node[i].Data.am,Node[i].Data.bathmos , Node[i].Next);
    printf("\n");
}

float FindMins(ListPointer List,NodeType Node[],StackType *Stack){
int CurrPtr;
int  min;
StackElementType Item;

CreateStack(&(*Stack));
if(!EmptyList(List)){
    CurrPtr=List;
    min=Node[CurrPtr].Data.bathmos;
    while(CurrPtr!=NilValue){
        if(Node[CurrPtr].Data.bathmos<=min){
            if(Node[CurrPtr].Data.bathmos<min){
                   while(EmptyStack(*Stack)){
                    Pop(&(*Stack),&Item);
                   }
                   Node[CurrPtr].Data.bathmos=min;
            }
            Push(&(*Stack),Node[CurrPtr].Data.am);
        }
        CurrPtr--;
    }
}else{
   printf("Empty List...\n");
  }
return  min;
}

void CreateStack(StackType *Stack)
{
  Stack -> Top = -1;
}

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else{
        printf("Full Stack...");
    }
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

boolean FullStack(StackType Stack)
{
     return (Stack.Top == (StackLimit - 1));
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
