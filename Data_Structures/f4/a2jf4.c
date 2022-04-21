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
void insert_list_m_elements(ListPointer *List,int n);

int main(){
 ListPointer AList;
 ListElementType Item;
 int i,n,k;
  CreateList(&AList);
  printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS: ");
  scanf("%d",&k);
  for(i=0;i<k;i++){
    printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS: ");
    scanf("%d",&Item);
    LinkedInsert(&AList,Item,NULL);
  }
  printf("************Arxiki lista************\n");
  LinkedTraverse(AList);
  printf("\nDWSE TI THESI,META APO TIN OPOIA THA EISAXTHOUN TA STOIXEIA: ");
  scanf("%d",&n);
  insert_list_m_elements(&AList,n);
  printf("************Teliki lista************\n");
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

void insert_list_m_elements(ListPointer *List,int n)
{
    ListElementType Item;
    ListPointer TempPtr;
    int i,j,m;
     if(EmptyList(*List)){
        printf("EMPTY LIST\n");
     }else{
        TempPtr=*List;
        i=0;
        while(TempPtr->Next!=NULL && i!=n-1){
            TempPtr=TempPtr->Next;
            i++;
        }
        if(i<n-1 || n<1){
            printf("ERROR\n");
        }else{
           printf("DWSE TO PLITHOS TWN STOIXEIWN POU THA EISAXTHOUN: ");
           scanf("%d",&m);
           for(j=0;j<m;j++){
             printf("DWSE TON ARI8MO GIA EISAGWGH STH LISTA: ");
             scanf("%d",&Item);
             LinkedInsert(&(*List),Item,TempPtr);
             TempPtr=TempPtr->Next;
           }
        }
     }
}
