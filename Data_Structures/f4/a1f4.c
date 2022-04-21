#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 10

#define NilValue -1

typedef int ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void TraverseLinked(ListPointer List, NodeType Node[]);
boolean Search(ListPointer FreePtr,ListPointer List,NodeType Node[],ListElementType Item,ListPointer *PredPtr);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);


int main(){
  NodeType N[NumberOfNodes];
  ListPointer ptr,L,pred,i;
  ListElementType Item;
  boolean found;
  char ch;
   InitializeStoragePool(N,&ptr);
   CreateList(&L);
   printf("-----------Question C----------\n");
   printf("-----------Storage pool--------\n");
   printAll(L,ptr,N);
   printf("-----------Question D-----------\n");
   printf("-----------Linked list----------\n");
   TraverseLinked(L,N);
   printf("-----------Question E-----------\n");
   do{
     printf("Give a number: ");
     scanf("%d",&Item);
     printf("\n");
     found=Search(ptr,L,N,Item,&pred);
     Insert(&L,N,&ptr,pred,Item);
     printf("Continue Y/N: ");
     do{
        scanf("%c",&ch);
     }while( toupper(ch)!='Y' && toupper(ch)!='N' );
   }while(toupper(ch)!='N');
   printf("-----------Question F------------\n");
   printf("-----------Storage pool----------\n");
   printAll(L,ptr,N);
   printf("-----------Question G------------\n");
   printf("-----------Linked list-----------\n");
   TraverseLinked(L,N);
   printf("----------Question H------------\n");
     if(EmptyList(L)){
        printf("Empty List\n");
     }else{
        printf("Not an Empty List\n");
    }
   printf("-----------Question I------------\n");
    if(FullList(ptr)){
        printf("Full List\n");
    }else{
        printf("Not a Full List\n");
    }
   printf("-----------Question J------------\n");
    for(i=0;i<=1;i++){
        printf("Give a number ");
        scanf("%d",&Item);
        found=Search(i,L,N,Item,&pred);
         if(found){
            printf("The number is in the list and its predecessor is in position %d\n",pred);
         }else{
           printf("The number is not in the list\n");
         }
    }
 return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=-1;
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
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
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
          printf("(%d: %d->%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
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
        printf("(%d: %d->%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}

boolean Search(ListPointer FreePtr,ListPointer List,NodeType Node[],ListElementType Item,ListPointer *PredPtr){
 boolean found,stop;
 ListPointer  current;
  stop=FALSE;
  found=FALSE;
  *PredPtr=NilValue;
  if(!EmptyList(List)){
    current=List;
    while(current!=NilValue && !stop){
        if(Node[current].Data>=Item){
            stop=TRUE;
            found=(Node[current].Data==Item);
        }else{
           *PredPtr=current;
           current=Node[current].Next;
        }
    }
  }else{
     found=FALSE;
  }
  return found;
}
