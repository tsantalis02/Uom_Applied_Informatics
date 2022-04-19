#include <stdio.h>
#include "simpio.h"

#define N 5

void readData(int A[][N]);
void FindMean(int A[][N],int which_row,double *mo_mens,double *mo_womens);


int main()
{
  int A[4][N];
  double baros_andrwn,baros_gynaikwn,ypsos_andrwn,ypsos_gynaikwn,ilikia_andrwn,ilikia_gynaikwn;
  readData(A);
  FindMean(A,2,&baros_andrwn,&baros_gynaikwn);
  printf("Mesos oros barous andrwn: %.1f \n ",baros_andrwn);
  printf("Mesos oros barous gynaikwn: %.1f \n",baros_gynaikwn);
  printf("                               \n");
  FindMean(A,3,&ypsos_andrwn,&ypsos_gynaikwn);
  printf("Mesos oros ypsous andrwn: %.1f \n",ypsos_andrwn);
  printf("Mesos oros ypsous gynaikwn: %.1f \n",ypsos_gynaikwn);
  printf("                                \n");
  FindMean(A,4,&ilikia_andrwn,&ilikia_gynaikwn);
  printf("Mesos oros ilikias andrwn: %.1f \n",ilikia_andrwn);
  printf("Mesos oros ilikias gynaikwn: %.1f \n",ilikia_gynaikwn);
return 0;
}

void readData(int A[][N]){
 int i,j;
 for(j=1;j<=N;j++)
 {
    for(i=1;i<=4;i++)
    {
        switch(i)
        {
         case 1:
          printf("Dwse fylo: ");
          A[i][j]=GetInteger();
          break;
         case 2:
           printf("Dwse baros: ");
           A[i][j]=GetInteger();
           break;
         case 3:
            printf("Dwse ypsos: ");
            A[i][j]=GetInteger();
            break;
         case 4:
            printf("Dwse ilikia: ");
            A[i][j]=GetInteger();
            break;
        }
     }
      printf("-----\n");
 }
}

void FindMean(int A[][N],int which_row,double *mo_mens,double *mo_womens){
 int i,j,sum1=0,sum2=0,counter1=0,counter2=0;
 for(j=1;j<=N;j++)
 {
     if(A[1][j]==0){
        sum1=sum1+A[which_row][j];
        counter1++;
     }else{
        sum2=sum2+A[which_row][j];
        counter2++;
     }
 }
 *mo_mens=sum1/(counter1*1.0);
 *mo_womens=sum2/(counter2*1.0);
}
