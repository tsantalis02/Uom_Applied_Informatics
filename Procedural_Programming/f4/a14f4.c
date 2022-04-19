#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int max (int a,int b);
int gr (int a,int b,int c);

int main(){
int a,b,c;
double y;
printf ("Dwse a :");
a=GetInteger();
printf ("Dwse b :");
b=GetInteger();
printf ("Dwse c :");
c=GetInteger();
y=((2*max(a,b)+3*gr(a,b,c))/4.0);
printf ("y = % .2f \n",y);
return 0;}

int max(int a,int b){
int megisto;
 if (a>b){
    megisto=a;
 }else{
   megisto=b;
 }
return megisto;}


int gr(int a,int b,int c){
int maximum;
 maximum=max(a,b);
  if(c>maximum){
    maximum=c;
  }
return maximum;}
