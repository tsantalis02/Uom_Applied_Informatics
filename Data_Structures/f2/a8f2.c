#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define StackLimit 80

typedef char StackElementType;

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

int main(){
StackType S;
StackElementType ch,x;
boolean flag=FALSE;
CreateStack(&S);
printf("Enter string:");
do{
    scanf("%c",&ch);
    getchar();
    if(ch!='C'){
    Push(&S,ch);
    }
    if(ch=='#') break;
}while(ch!='C');
if(ch!='#'){
 do{
    scanf("%c",&ch);
    getchar();
    if(ch!='#'){
    Pop(&S,&x);
    }
    if(ch=='#') break;
    if(ch==x ){
        flag=TRUE;
    }else{
        flag=FALSE;
      break;
    }
 }while(ch!='#');
}
if(flag  && EmptyStack(S)){
    printf("TRUE");
}else{
  printf("FALSE");
}
return 0;}


void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
}

boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
}
}
