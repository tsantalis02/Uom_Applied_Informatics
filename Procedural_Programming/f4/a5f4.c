#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int cube (int digit);
bool IsArmstrong(int number);
int sum_cube(int number);

int main (){
int k;
 //printf("Dwse arithmo:");
 //number=GetInteger();
 for(k=1;k<1000;k++){
if(IsArmstrong(k)){
    printf("%d is an Armstrong number\n",k);
}
 }
return 0;
}


int cube(int digit){
 int i,gin;
 gin=1;
 for(i=0;i<3;i++){
    gin *=digit;
 }
return gin;
}
bool IsArmstrong(int number){
return(number==sum_cube(number));
}
int sum_cube(int number){
 int sum=0;
 while(number>0){
    sum+=cube(number%10);
    number/=10;
}
return sum;
}
