/*
File name:a20f5.c

*-----------------------------

    �� ������ ��� ��������� �� ����� �� �������� 5 ��������� ��� �� ���� ���������� �� ���� ������. ���
    ��������, �� ��������� �� ����������� �� �������� ��� ������ ��� ���� ����� ��� �� ������� ��� ������
    ���� �����. ��� ����������, �� �� �������� ��� ������ �����: 1, -9, 5, 3, 4 � ������� ���� ��� ����������
    �� �����: 4, 1, -9, 5, 3. � �������� �������� ��������.

*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

#define N 5 //Numbers


int main(){
int pinakas[N],i,k;
/*Read 5 numbers*/
 for(i=0;i<N;i++){
    printf("Enter number:");
    pinakas[i]=GetInteger();
 }
 /*Rotate*/
 for(i=N-1;i>0;i--){
    if (i==N-1){
        k=pinakas[i];
    }
    pinakas[i]=pinakas[i-1];
   }
 pinakas[0]=k;
  for(i=0;i<N;i++){
    printf("%d ",pinakas[i]);
 }
return 0;}
