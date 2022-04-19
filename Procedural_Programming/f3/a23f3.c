#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int main(){
int k,i;
printf("Enter number:");
k=GetInteger();
 if(k%2==0){
    for(i=0;i<=k;i+=2){
            printf("%d ",i);}
 }else{
   for(i=1;i<=k;i+=2){
    printf("%d ",i);}
 }
return 0;}
