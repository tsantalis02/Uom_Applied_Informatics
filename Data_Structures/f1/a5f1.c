#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define plithos 1001

typedef enum{
  FALSE,TRUE
}boolean;

typedef boolean typos_synolou[plithos];
typedef int stoixeio;

boolean isFibonacci(stoixeio n,typos_synolou F);
void createFibonacciSet(stoixeio threshold,typos_synolou F);
void displaySet(typos_synolou F,stoixeio threshold);
boolean Melos(stoixeio n,typos_synolou F);
void Eisagogi(stoixeio ,typos_synolou F);
void Dimiourgia(typos_synolou F);

int main(){
stoixeio max,number;
typos_synolou F;
printf("Dwse to megisto arithmo. ");
scanf("%d",&max);
while(max<2 || max>1000){
    printf("Dwse to megisto arithmo. ");
    scanf("%d",&max);
}
createFibonacciSet(max,F);
displaySet(F,max);
printf("Enter number to check:");
scanf("%d",&number);
while(number!=-1){
    if(isFibonacci(number,F)){
        printf("Fibonacci!\n");
    }else{
       printf("Not Fibonacci...\n");
    }
    printf("Enter number to check:");
    scanf("%d",&number);
    if(number==-1)
    {
        system("PAUSE");
    }
}
return 0;}

void createFibonacciSet(stoixeio threshold,typos_synolou F){
stoixeio temp1,temp2,sum;
Dimiourgia(F);
temp2=0;
Eisagogi(temp2,F);
temp1=1;
Eisagogi(temp1,F);
do{
if(temp2==0){
    temp2=temp1;
    temp1=2;
    Eisagogi(temp1,F);
    sum=temp1;
}else{
    sum=temp1+temp2;
    if(sum<=threshold)
    {
    Eisagogi(sum,F);
    }
    temp2=temp1;
    temp1=sum;
}
}while(sum<=threshold);
}
void displaySet(typos_synolou F,stoixeio threshold){
stoixeio i;
for(i=0;i<plithos;i++){
    if(Melos(i,F)){
        printf(" %d",i);
    }
}
printf("\n");
}

boolean isFibonacci(stoixeio n,typos_synolou F)
{
return (Melos(n,F));
}

boolean Melos(stoixeio n,typos_synolou F)
{
return F[n];
}

void Dimiourgia(typos_synolou F)
{
stoixeio i;
     for (i = 0; i < plithos; i++)
        F[i] = FALSE;
}

void Eisagogi(stoixeio n,typos_synolou F)
{
F[n]=TRUE;
}
