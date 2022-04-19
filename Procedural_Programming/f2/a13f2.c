#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
 int kafedes,kostos,x,y,z,n,m,ypoloipo;
 printf("Dwse kafedes :");
 kafedes=GetInteger();
 kostos=kafedes*70;
  if (kostos>500){
    printf("Den ftanoun ta xrhmata gia tosous kafedes");
  }else{
   ypoloipo=500-kostos;
   x=ypoloipo/200;
   ypoloipo=ypoloipo%200;
   y=ypoloipo/100;
   ypoloipo=ypoloipo%100;
   z=ypoloipo/50;
   ypoloipo=ypoloipo%50;
   n=ypoloipo/20;
   ypoloipo=ypoloipo%20;
   m=ypoloipo/10;
   ypoloipo=ypoloipo%10;
   printf("Resta \n");
   printf("Kermata 2E :%d\n",x);
   printf("Kermata 1E :%d\n",y);
   printf("Kermata 50L :%d\n",z);
   printf("Kermata 20L :%d\n",n);
   printf("Kermata 10L :%d\n",m);
  }
return 0;
}
