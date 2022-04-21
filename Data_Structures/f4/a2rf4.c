#include <stdio.h>
#include <stdlib.h>


typedef int ListElementType;

typedef struct ListNode *ListPointer;
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
ListElementType RemoveMins(ListPointer *InList);

int main(){
 ListPointer AList;
 ListElementType Item,min;
 int i,n;
  CreateList(&AList);
  printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS : ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS 1:");
    scanf("%d",&Item);
    LinkedInsert(&AList,Item,NULL);
  }
  printf("Traversing list\n");
  LinkedTraverse(AList);
  min=RemoveMins(&AList);
  printf("\nRemoving min from list\n");
  printf("Min was %d\n",min);
  printf("Traversing list with min removed\n");
  LinkedTraverse(AList);
  return 0;
}

void CreateList(ListPointer *List)
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
 /*  printf("Insert &List %p, List %p,  &(*List) %p, (*List) %p, TempPtr %p\n",
   &List, List,  &(*List), (*List), TempPtr); */
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}



void LinkedTraverse(ListPointer List)
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
       CurrPtr=List;
       while(CurrPtr!=NULL){
   	    printf("%d ",CurrPtr->Data);
   	    CurrPtr=CurrPtr->Next;
       }
   	  /*  printf("%-16s\t%-4s\t%-16s\n", "CurrPtr","Data","Next");
        while ( CurrPtr!=NULL )
        {
             printf("%p\t%d\t%p\n",CurrPtr,(*CurrPtr).Data, (*CurrPtr).Next);
             CurrPtr = CurrPtr->Next;
        }
        */
   }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}


ListElementType RemoveMins(ListPointer *InList)
{
  ListPointer CurrPtr,PredPtr;
  ListElementType min;
   CurrPtr=*InList;
   min=CurrPtr->Data;
    while(CurrPtr!=NULL){
        if(CurrPtr->Data<min){
            min=CurrPtr->Data;
        }
        CurrPtr=CurrPtr->Next;
    }
    CurrPtr=*InList;
    PredPtr=0;
    while(CurrPtr!=NULL){
        if(CurrPtr->Data==min){
            CurrPtr=CurrPtr->Next;
            LinkedDelete(&(*InList),PredPtr);
        }else{
          PredPtr=CurrPtr;
          CurrPtr=CurrPtr->Next;
        }
    }
return min;
}
