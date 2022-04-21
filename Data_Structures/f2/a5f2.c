#include <stdio.h>
#include <stdlib.h>
#define StackLimit 15

typedef int StackElementType;

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

int main()
{
StackElementType i,n,x,temp;
StackType S,TempS;

CreateStack(&S);
CreateStack(&TempS);
for(i=0;i<150;i=i+10){
    Push(&S,i);
}
TraverseStack(S);
printf("Give nth element (n<=%d) ",(S.Top-1)/2);
scanf("%d",&n);
printf("\n \n");
Pop(&S,&x);
Pop(&S,&x);
printf("Question a: x=%d",x);
TraverseStack(S);
Pop(&S,&temp);
Pop(&S,&x);
Push(&S,x);
Push(&S,temp);
printf("\n \n");
printf("Question b: x=%d",x);
TraverseStack(S);
for(i=0;i<n;i++){
    Pop(&S,&x);
}
printf("\n \n");
printf("Question c: x=%d",x);
TraverseStack(S);
printf("\n \n");
for(i=0;i<n;i++){
    Pop(&S,&x);
    Push(&TempS,x);
}
printf("Question d: x=%d",x);
while(EmptyStack(TempS)==FALSE){
    Pop(&TempS,&temp);
    Push(&S,temp);
}
TraverseStack(S);
while(EmptyStack(S)==FALSE){
    Pop(&S,&x);
    Push(&TempS,x);
}
printf("\n \n");
printf("Question e: x=%d",x);
while(EmptyStack(TempS)==FALSE){
    Pop(&TempS,&temp);
    Push(&S,temp);
}
TraverseStack(S);
while(S.Top!=1){
    Pop(&S,&x);
    Push(&TempS,x);
}
printf("\n \n");
printf("Question f: x=%d",x);
while(EmptyStack(TempS)==FALSE){
    Pop(&TempS,&temp);
    Push(&S,temp);
}
TraverseStack(S);
while(EmptyStack(S)==FALSE){
    Pop(&S,&x);
}
printf("\n \n");
printf("Question g: x=%d",x);
TraverseStack(S);
return 0;
}

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
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
