/*
File name:a1bf3.c

*-----------------------

 �� ������� ��������� ��� ���� ��� ��� ��� �������� �����������:
    a. � ��������� ������� ����������� ��� ����������� �� ��� ���� ����� 80000. �� � ������� ����� ��������� �� ����� 7%,
    �� ������ ��������� ��� �� ���������� �� ���� ������ � ������� ��� ����������� �� ��������� ��� 160000.
    ���� �� ����� ���� �� ����������;
    b. ���������� �� ��������� ��� �rithmo_�ytok (long) ����������, ��� ���������� �� ������ ����� Rythmos ��� ���������
    ��� ������� ���� �rio (long), �������� �� ����� �� ������� � �������.
    �� ����������� a ��� b �� ���������� �� ��� (long) ��� ��� ������ ��� ����������� (long) ���� �� ��������� �� ������� ����.
    ��� ��� ���������� ��� ������� ������� ����������� �� �������������� � �����:
	������� ����������� = ceil(������� ����������� *(1+������ �������))
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int main(){
/*������-������������ ����������*/
long Arithmo_Aytok,Orio,years;
double Rythmos;
/*�������� ���������*/
printf("Dwse ton arxilko arithmo  aytokinitwn :");
Arithmo_Aytok=GetLong();
printf("Dwse ton ethsio rythmo ayxhshs :");
Rythmos=GetReal();
printf("Dwse to orio :");
Orio=GetLong();
years=0;
/*�����������*/
 while(Arithmo_Aytok<=Orio){
    Arithmo_Aytok=ceil(Arithmo_Aytok*(1+Rythmos));
    years=years+1;
 }
/*�������� �������������*/
printf("%ld\n",years);
printf("%ld\n",Arithmo_Aytok);
return 0;
}
