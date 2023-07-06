/*
File name:a29f4.c

*-----------------------------

 ����������� ��� ����������� ����������� ���� ������ C ��� ��������� ����������� �������:
   � � �������� ������ ��������� (gdc) ��� �� ��������� �������� ������� ��� ��� �������� ���������� ������:
	      gcd (a , b)= a , ��� b=0
	      gcd (a , b)= gcd ( b , a % b), ������
   � ��� �������� ������� �������� ������� ������ (coprime) �� � �������� ������ ��������� ���� ����� �� 1.
   � � ��������� � ��� Euler (phi) ���� ������� �������� � ����� �� ������ ��� ������� �������� ������� ����������
   � ���� ��� �, �� ������ ����� ������� ������ �� �� � (������ �� �������� � �� 1 <= � <= �).
   �� ����������� ��� ��������� �� C, �� ����� ���� ��� ��� ������ ��� ������� � ��� ��������� ��� ����� ��� ���������� �
   ��� Euler ��� �� 1 ����� ��� ��� ������ X. ��������� ��� � ������� ����� ����� ������ ���������� � ��� ��� 1 - ��� ���������� �������.
   � �������� ��� ��������� �� ������� ���� ��� ������ ������������ (��������� main(), ������ � ������ ��������� ��� ��������� (printf)
   �� ����� ���� main()).
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

  int gcd(int k,int X );
  int phi(int i);

 int main(){
 int X,i;
 printf("Enter X:");
 X=GetInteger();
 for(i=1;i<=X;++i){
    printf("phi(%d)=%d\n",i,phi(i));
 }
 return 0;}

 int phi(int i){
 int k,s;
 s=0;
  for(k=1;k<=i;++k){
    if(gcd(k,i)==1)
        s+=1;
  }
 return s;}

int gcd(int k,int i){
int n,mkd;
 for(n=1;n<=k && n<=i;++n){
    if(k%n==0 && i%n==0)
        mkd=n;
 }
return mkd;}