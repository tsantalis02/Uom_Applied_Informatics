#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int ypof(int x);
int ypog(int x,int y);
int yposin(int x, int y);

int main(){
int x,y;
printf("Enter x:");
x=GetInteger();
printf("Enter y:");
y=GetInteger();
printf("f(x)=f(%d)=%d\n",x,ypof(x));
printf("g(x,y)=g(%d,%d)=%d\n",x,y,ypog(x,y));
printf("f(g(x,y))=f(g(%d,%d))=%d\n",x,y,yposin(x,y));
return 0;}

 int ypof(int x){
  if (x>0){
    return x+2;
  }else{
   return -3*x+7;
  }
 }

 int ypog(int x,int y){
  if(x>0 && y>0){
    return x-y;
  }else{
    return 7*x-5;
  }
 }

 int yposin(int x,int y){
  if (x>0 && y>0){
    return x-y+2;
  }else if(x>0 && y<0){
      return 7*x-3;
  }else {
    return -21*x+22;
  }
 }
