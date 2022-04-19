#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "genlib.h"



void populate_data(int U,int V,int row,int col,int A[row][col]);
void print_array(int U,int V,int row,int col,int A[row][col]);
int change_array(int U,int V,int row,int col,int A[row][col]);


int main()
{
int R,C,K=10,L=10,A[10][10];
printf("Dwse ton arithmo twn grammwn:");
R=GetInteger();
printf("Dwse ton arithmo twn sthlwn:");
C=GetInteger();
populate_data(R,C,K,L,A);
printf("ARXIKOS PINAKAS \n");
print_array(R,C,K,L,A);
change_array(R,C,K,L,A);
printf("ALLAGMENOS PINAKAS \n");
print_array(R,C,K,L,A);
return 0;
}

void populate_data(int U,int V,int row,int col,int A[row][col])
{
 int i,j;
 for(i=0;i<U;i++)
 {
     for(j=0;j<V;j++)
     {
         A[i][j]=rand() % 100;
     }
 }
}

void print_array(int U,int V,int row,int col,int A[][col])
{
int i,j;
for(i=0;i<U;i++)
{
    for(j=0;j<V;j++)
    {
        printf("%7d",A[i][j]);
    }
printf("\n");
}
}

int change_array(int U,int V,int row ,int col,int A[][col])
{
int megisto,i,j,thesi;
for(i=0;i<U;i++)
{
    megisto=-1;
    for(j=0;j<V;j++)
    {
        if(A[i][j]>megisto)
        {
            megisto=A[i][j];
            thesi=j;
        }
    }
    if(thesi!=0)
    {
        for(j=0;j<thesi;j++)
        {
            A[i][j]=megisto;
        }
    }
}
}
