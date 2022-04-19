#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

#define R 5

int main(){
double P[R],DIAF[R-1];
int i;
for (i=0;i<R;i++){
    printf("Enter number (%d):",i);
    P[i]=GetReal();
}
 for(i=0;i<R-1;i++){
   DIAF[i]=fabs(P[i+1]-P[i]);
 }
 for(i=0;i<R;i++){
    printf("%.2f ",P[i]);
 }
 printf("\n");
for(i=0;i<R-1;i++){
    printf("%.2f ",DIAF[i]);
}
return 0;}
