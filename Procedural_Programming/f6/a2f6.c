/*
File:a2f6.c

Άδεια χρήσης: GNU General Public License v3.0

*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define K 100
int populateArray(int A[]);
void checkArray(int A[],int pl,int *max,int *min );

int main()
{
   int A[K],plithos,elaxisto,megisto,i;
   for(i=0;i<100;i++)
   {
       A[i]=0;
   }
   printf("Enter the elements of the array,one per line.\n");
   printf("Use -1 to signal the end of the list.\n");
   plithos=populateArray(A);
   checkArray(A,plithos,&megisto,&elaxisto);
   printf("The range of values is %d-%d",elaxisto,megisto);
   return 0;
}



int  populateArray(int A[])
{
    int i=0,k,sum=0;
    do
    {
        printf("? ");
        k=GetInteger();
        if(k!=-1)
        {
            A[i]=k;
            i=i+1;
            sum=sum+1;
        }

    }while(k!=-1);
    return sum;
}

void checkArray(int A[],int pl,int *max,int *min)
{
 int i;
 *max=-10;
 *min=500^2;
 for(i=0;i<pl;i++)
 {
   if(A[i]>*max)
   {
       *max=A[i];
   }
    if(A[i]<*min)
   {
       *min=A[i];
   }
 }
}
