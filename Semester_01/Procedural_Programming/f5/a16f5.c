/*
File name:a16f5.c

*---------------------------------------

 �� ���������� (�� �� ����� ��� ����������� ��� �������������) ��������� ��� �����,
    - �� ������� ��� ������ a �������� 50 �� �������� �������� ��� �� 0 ��� �� 9 ��������������� ���
    ��������� rand() (a[i]=rand() % 10), ��� ����������� <stdlib.h> (��������� populate)
    - �� ��������� ��� ������ a ���� ����� (��������� printArr),
    - �� ���� ���� ������� ������ � ��� �� 0 ��� ��� �� 9 ��� ��� ������ - ��� ���������� �������,
    - �� ����� ��� ��������� checkTable, � ����� �� ���������� ��� ������ ��� ���������� ��� ������� � ���� ������ a
    ��� ��� ������ ��� ������ ���� ������ ����������� � �������
    - �� ��������� �� ������������ ��� ������, ���� �������� ��� ���������� ���������. � �������� ��� �������������
    �� ������� ��� �� ��������� main() (������ ���������), ��� ��� ������ ��� ����������� � ������� � �������� ��� printArr.
*/
#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include <math.h>



void populate(int size,int a[]);
void printArr(int size,int a[]);
int checkTable(int size,int a[],int N,int T[]);

int main()
{
int size=50,a[size],N,plithos,T[plithos];
/*���������� ������ (Create the table a)*/
populate(size,a);
/*�������� ������� ������ (Print initial table)*/ 
printArr(size,a);
/*�������� ��������� (Read Data)*/
printf("Dwse arithmo apo to 1 ews to 9: ");
N=GetInteger();
plithos=checkTable(size,a,N,T);
/*�������� ������������� (Print results)*/
printf("O arithmos %d emfanisthke %d fores. \n",N,plithos);
printf("Stis Theseis: \n");
printArr(plithos,T);
return 0;
}


void populate(int row,int A[])
{
int i;
  for(i=0;i<row;i++)
  {
      A[i]=rand() % 10 ;
  }
}

void printArr(int row,int A[])
{
int i;
    for(i=0;i<row;i++)
    {
        printf("%7d",A[i]);
    }
printf("\n");
}

int checkTable(int row,int A[],int N,int K[])
{
int i,r=0;
    for(i=0;i<row;i++)
    {
        if(A[i]==N)
        {
          r+=1;
          K[r]=i;
       }
   }
return r;
}
