#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define StackLimit 10
typedef struct{
  char size;
  int price;
} StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);

int main(){
StackType box,out;
StackElementType F;
int n,i;
char s;
boolean found=FALSE;
CreateStack(&box);
CreateStack(&out);
printf("Give number of items ");
scanf("%d",&n);
printf("Give the items to store \n");
for(i=0;i<n;i++){
    printf("Give price ");
    scanf("%d",&F.price);
    getchar();
    printf("Give size ");
    scanf("%c",&F.size);
    Push(&box,F);
}
printf("\n");
printf("Items in the box ");
TraverseStack(box);
getchar();
printf("What size do you want? ");
scanf("%c",&s);
i=0;
while(i<n && found==FALSE){
    if(box.Element[i].size==s){
        found=TRUE;
        Pop(&box,&F);
        break;
    }else{
       Pop(&box,&F);
       Push(&out,F);
    }
 i++;
}
if(found){
    printf("Found the size %c ",s);
}else{
   printf("Not Found the size %c ",s);
}
printf("\nItems in the box");
TraverseStack(box);
printf("Items out of the box");
TraverseStack(out);
while(i<out.Top || EmptyStack(out)==FALSE){
    Pop(&out,&F);
    Push(&box,F);
}
printf("\nItems in the box");
TraverseStack(box);
printf("Items out of the box");
TraverseStack(out);
return 0;}

void CreateStack(StackType *Stack)
{
  Stack -> Top = -1;
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

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
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
        printf("%c, %d \n",Stack.Element[i].size,Stack.Element[i].price);
    }
    printf("\n");
}
