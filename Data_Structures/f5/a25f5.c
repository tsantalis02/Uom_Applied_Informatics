#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef int BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTInorder(BinTreePointer Root);
int CountLeaves(BinTreePointer Root);

int main(){
  BinTreePointer ARoot;
  BinTreeElementType n;
  char ch;

  CreateBST(&ARoot);
  do{
    printf("Enter a number for insertion in  the Tree:");
    scanf("%d",&n);
    RecBSTInsert(&ARoot,n);
    printf("Continue Y/N:");
    do{
        scanf("%c", &ch);
      } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
  }while (toupper(ch)!='N');
  printf("Elements of BST\n");
  RecBSTInorder(ARoot);
  printf("\nNumber of leaves %d",CountLeaves(ARoot));
  return 0;
  }

 void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item < (*Root) ->Data)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item > (*Root) ->Data)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}


 void RecBSTInorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        RecBSTInorder(Root->LChild);
        printf("%d ",Root->Data);
        RecBSTInorder(Root->RChild);
    }
}

int CountLeaves(BinTreePointer Root){
  if(BSTEmpty(Root)){
    return 0;
  }else if(Root->LChild==NULL && Root->RChild==NULL){
    return 1;
    }else{
     return(CountLeaves(Root->LChild)+CountLeaves(Root->RChild));
    }
}
