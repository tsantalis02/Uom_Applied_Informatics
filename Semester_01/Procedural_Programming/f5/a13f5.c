/*
File name:a13f5.c

*----------------------------

 �� ������ ��������� �� �����:
    (�) �� ���� ��� ��� ������ ��� �������� ��������� �������� R (�������) ��� C (������) ��� �� 1 �����
    ��� �� 10. �������� �� ��������� �� �������� ��� � ������� �� ������� ������� ������� ������� �� ��
    ����������� ����. ��� ���������� �������. � �������� �� ������� ��� ��� ��������� main.
    (�) �� "�������" �� �������� R x C ���� ����������� ������ � �������� (��������� 10x10) �� ��������
    ��������� ��� 0 ��� ��� 99 (rand() % 100), ���� ������ ���� ���������� populate_data.
    ������ �� ��������� �� ������������ ����� ��� ������ �, ����� ��� ������� R ��� C, ��� �������� � �������.
    (�) �� ����� ��� ��������� print_array ��� �� ������� �� R x C �������� ��� ������ �.
    (�) �� ����� ��� ���������� change_array, � ����� ��� ���� ������ ��� ������ � �� ����� ���
    �������� ����� �������� ��� �������� ��� ������� ��� �� ���� (������ ��� ����� ���� ���� ������ �� ����,
    ���� ����� ��������� ������ ������ �� ������ ��� �� �� �������).
    (�) �����, �� ������������ ��� ���� �� �������� ��� "����������" ������ ���� �������.
    ���� �� ����������� ��� �� ���������� �� ������� C99 ��� ������� 2 ����������. ������� ���� �������� ��� ���������� ��� �����������.
    ����� ���� � �������� ��� ������, ��� ���� ���� ����� ��� ������ ���� ��������������. �� ������ �� �������� ������������ �����������.
*/
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
//�������� ���������(Read Data)
printf("Dwse ton arithmo twn grammwn:");
R=GetInteger();
printf("Dwse ton arithmo twn sthlwn:");
C=GetInteger();
//���������� ������(Create the table A )
populate_data(R,C,K,L,A);
//�������� ������� ������(Printing initial table)
printf("ARXIKOS PINAKAS \n");
print_array(R,C,K,L,A);
change_array(R,C,K,L,A);
//�������� ���������� ������(Printing changed table)
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
