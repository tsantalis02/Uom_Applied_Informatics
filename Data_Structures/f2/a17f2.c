#include <stdio.h>
#include<stdlib.h>

#define StackLimit 80

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
StackType CopyStack(StackType *Stack);

int main(){
 StackType s1,s2;
 StackElementType i,temp;
  CreateStack(&s1);
  CreateStack(&s2);
   for(i=0;i<20;i++){
    Push(&s1,i);
   }
  printf("Stack s1 ");
  TraverseStack(s1);
  printf("After copying s1 to s2 \n");
  printf("Stack s1 ");
  TraverseStack(s1);
  s2=CopyStack(&s1);
  printf("Stack s2 ");
  TraverseStack(s2);
return 0;}

void CreateStack(StackType *Stack)

{
    Stack -> Top = -1;
}

boolean EmptyStack(StackType Stack) {
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item){
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item) {
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else{
        printf("Empty Stack...");
}
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

StackType CopyStack(StackType *Stack)
{
StackElementType x,i;
 for(i=0;i<20;i++){
 Pop(&(*Stack),&x);
 Push(&(*Stack),x);
 }
}
