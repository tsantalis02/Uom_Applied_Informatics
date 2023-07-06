/*
File name:a13f6.c

*-------------------------

*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


void decompose(long ar,int *dig,double *mo,int *max);




int main()
{
  long n;
  int digits,megisto;
  double average;
  printf("Please insert non-negative number:");
  n=GetLong();
  decompose(n,&digits,&average,&megisto);
  printf("Digits: %d\n",digits);
  printf("Average: %.3f\n",average);
  printf("Max: %d\n",megisto);
  return 0;
}


void decompose(long ar,int *dig,double *mo,int *max)
{
  int piliko,ypoloipo,sum,ps,s;
  s=1;
  piliko=ar/10;
  ypoloipo=ar%10;
  ps=ypoloipo;
  sum=ps;
  *max=ps;
  while(piliko!=0)
    {
      s=s+1;
      if((piliko/10)!=0)
      {
        ps=piliko%10;
      }else{
        ps=piliko;
      }
      piliko=piliko/10;
      if(ps>*max)
      {
          *max=ps;
      }
      sum=sum+ps;
    }
   if(s!=0)
   {
    *mo=sum / (s * 1.0);
   }
   *dig=s;
}
