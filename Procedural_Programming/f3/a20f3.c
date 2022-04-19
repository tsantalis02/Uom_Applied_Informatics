#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int main(){
int ilikia,max,min;
printf("Dwse ilikia: ");
ilikia=GetInteger();
 if (ilikia>=0){
    max=ilikia;
    min=ilikia;
 }
 while(ilikia>=0){
    printf("Dwse ilikia: ");
    ilikia=GetInteger();
     if (ilikia>max){
        max=ilikia;
     }
     if (ilikia!=-1){
       if(ilikia<min){
        min=ilikia;
       }
     }
 }
printf("H megalyteri ilikia einai %d\n",max);
printf("H mikroteri ilikia einai  %d\n",min);
return 0;
}
