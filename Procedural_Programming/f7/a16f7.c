#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "simpio.h"

#define N 100

void checkDigit(char A[]);

int main(){
 char A[N];
  printf("Insert a string: ");
  gets(A);
  checkDigit(A);
 return 0;
}


void checkDigit(char A[]){
  int i,j=-1,s=-8;
   for(i=0;i<N;i++){
    if(A[i]>='0' && A[i]<='9'){
     s+=(A[i]-48);
     j+=1;
      if(j==0 && A[i]!='8'){
        printf("%d",A[i]-48);
      }else{
        if(A[i]!= '8'){
         printf(" + %d",A[i]-48);
        }
      }
    }
   }
   if(j==-1 || j==0){
    printf("No digits in input. \n");
   }else{
    printf(" = %d \n",s);
   }
}
