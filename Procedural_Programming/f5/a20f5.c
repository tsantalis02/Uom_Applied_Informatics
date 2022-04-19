#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

#define N 5


int main(){
int pinakas[N],i,k;
 for(i=0;i<N;i++){
    printf("Enter number:");
    pinakas[i]=GetInteger();
 }

 for(i=N-1;i>0;i--){
    if (i==N-1){
        k=pinakas[i];
    }
    pinakas[i]=pinakas[i-1];
   }
 pinakas[0]=k;
  for(i=0;i<N;i++){
    printf("%d ",pinakas[i]);
 }
return 0;}
