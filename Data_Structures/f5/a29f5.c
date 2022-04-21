#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct{
  int amka,afm,age;
}BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void InorderTraversal(BinTreePointer Root);


int main(){
 BinTreePointer Root1,Root2,LocPtr;
 BinTreeElementType person;
 boolean found;
 char ch;
 int i;
  CreateBST(&Root1);
  CreateBST(&Root2);
  do{
    printf("Give AMKA?");
    scanf("%d",&person.amka);
    printf("Give AFM?");
    scanf("%d",&person.afm);
    printf("Give age?");
    scanf("%d",&person.age);
    if(person.age<=60){
        BSTInsert(&Root1,person);
    }else{
      BSTInsert(&Root2,person);
    }
    printf("\nContinue Y/N:");
    do{
        scanf("%c",&ch);
    }while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
  }while (toupper(ch)!= 'N');
  printf("\nPeople with age less-equal 60\n");
  InorderTraversal(Root1);
  printf("\n");
  printf("\nPeople with age greater than 60\n");
  InorderTraversal(Root2);
  printf("\n");
  for(i=0;i<3;i++){
    printf("Give AMKA:");
    scanf("%d",&person.amka);
    printf("Give age:");
    scanf("%d",&person.age);
    if(person.age<=60){
        BSTSearch(Root1,person,&found,&LocPtr);
    }else{
       BSTSearch(Root2,person,&found,&LocPtr);
    }
    if(found){
         if(person.age==LocPtr->Data.age){
            printf("The person with AMKA %d,AFM %d and age %d is on the catalogue\n",LocPtr->Data.amka,LocPtr->Data.afm,LocPtr->Data.age);
         }else{
            printf("The person with AMKA %d has age %d different from the person you are looking for \n",LocPtr->Data.amka,LocPtr->Data.age);
         }
    }else{
      printf("The person with AMKA %d and age %d not found\n",person.amka,person.age);
      printf("The person with AMKA %d and age %d is Unknown\n",person.amka,person.age);
    }
  }
  return 0;
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item.amka < LocPtr->Data.amka)
            LocPtr = LocPtr ->LChild;
        else if (Item.amka > LocPtr ->Data.amka)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %d EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data.amka = Item.amka;
        LocPtr->Data.afm=Item.afm;
        LocPtr->Data.age=Item.age;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.amka < Parent ->Data.amka)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (KeyValue.amka < (*LocPtr)->Data.amka)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (KeyValue.amka > (*LocPtr)->Data.amka)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}





void InorderTraversal(BinTreePointer Root)
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("(%d,%d,%d)",Root->Data.amka,Root->Data.afm,Root->Data.age);
        InorderTraversal(Root->RChild);
    }
}

