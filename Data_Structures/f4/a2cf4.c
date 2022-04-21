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
void concat_list(ListPointer AList,ListPointer BList,ListPointer *FinalList);

int main(){
 ListPointer AList,BList,FinalList;
 ListElementType Item,i,K;
  CreateList(&AList);
  CreateList(&BList);
  CreateList(&FinalList);
  printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS 1: ");
  scanf("%d",&K);
  for(i=0;i<K;i++){
    printf("DWSE TOM ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS 1: ");
    scanf("%d",&Item);
    LinkedInsert(&AList,Item,NULL);
  }
  printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS 2: ");
  scanf("%d",&K);
  for(i=0;i<K;i++){
    printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS 2: ");
    scanf("%d",&Item);
    LinkedInsert(&BList,Item,NULL);
  }
  printf("LISTA 1: \n");
  LinkedTraverse(AList);
  printf("\nLISTA 2: \n");
  LinkedTraverse(BList);
  concat_list(AList,BList,&FinalList);
  printf("\nSYNENWMENH LISTA: \n");
  LinkedTraverse(FinalList);
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


void concat_list(ListPointer AList,ListPointer BList,ListPointer *FinalList)
{
    ListPointer CurrPtr;
    CurrPtr=AList;
    while(CurrPtr!=NULL){
        LinkedInsert(&(*FinalList),CurrPtr->Data,NULL);
        CurrPtr=CurrPtr->Next;
    }
    CurrPtr=BList;
    while(CurrPtr!=NULL){
      LinkedInsert(&(*FinalList),CurrPtr->Data,NULL);
      CurrPtr=CurrPtr->Next;
    }
}
