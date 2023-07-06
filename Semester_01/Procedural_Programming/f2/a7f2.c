/*
File name:a7f2.c

*-------------------------

    �� ������ ��� ��������� C ��� ��� ���������� ��� ��� �������� ��� ������������ ������� ���� ����������� �� ����:
    �� ��������� �� �������� ��� ������ ������ (long) ��� �����������. �� � ������� ������� ����� ����������� � ���� ��� 1000,
    ���� �� ��������� �� �������� ��� ������ ����� ��� ����������� (double) ��� �� ���������� ��� ����������� ������ (double)
    ��� ���������� ��� ������ ����� ��� 52.
    �� � ������� ����� ���������� ��� 1000, ���� �� ��������� �� �������� ��� ���� ������������ �������� (int) ��� �����������,
    ��� ������ ��� ��� (double) ��� ��� �������� �� ���������� ��� ����������� ������. �� � ����������� ������� ����� ��� ���
    40 ����, ���� ��� ��� ���� ���� ��� 40 ���� � ������ ���� ���������� 50%.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main (){
 /*������-������������ ����������*/
 long kwdikos;
 int wres;
 double ethsios,ebdomadiaios,amoibhanawra;
 /*�������� ��������� ��� ����������� ������� �� ��� ����� �������� �������*/
 printf("Dwse ton kwdiko toy ergazomenoy :");
 kwdikos=GetLong();
  if (kwdikos >=1000){
   printf("Dwse ton ethsio mistho : ");
   ethsios=GetReal();
   ebdomadiaios=ethsios/52;
  }else{
   printf("Dwse tis wres ebdomadiaias ergasias :");
   wres=GetInteger();
   printf("Dwse thn amoibh ana wra :");
   amoibhanawra=GetReal();
    if (wres>40){
      ebdomadiaios=40*amoibhanawra+1.5*(wres-40)*amoibhanawra;
    }else{
    ebdomadiaios=wres*amoibhanawra;
    }
 /*�������� �������������*/
  printf("O ebdomadiaios misthos einai %g\n",ebdomadiaios);
  return 0;
}
