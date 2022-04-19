#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int main(){
int n,i;
float sum;
printf("Dwse orio :");
n=GetInteger();
sum=1;
i=2;
 while(i<=n){
   sum=sum+(1.0/i);
   i=i+1;
}
printf("To athroisma einai %.2f\n",sum);
return 0;
}
