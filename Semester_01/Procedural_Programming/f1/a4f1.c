/*
*File name:a4f1.c
*------------------------
���� ������� ������� �� ���� ��������� ����������� ����� purchaseAmount � ��� �� ������� saleAmount �.
    �� �� ���� saleAmount ��������� ��� ��� ������ ���� purchaseAmount ��� �� ������� ������� rate
    ��� ������� ��� ��� ������� ����� purchaseAmount, �� ����� ��������� ��� �� ���������� ��� �� ���������:
    �) �� ������ ��� ������� profit (double),
    �) �� ���������� ���� saleAmount (double).
    �� �������� ������� �� ����� �� �����:
    purchaseAmount (��������� ����� long)
    rate (��������� ����� int, ��� �� ������� ������� ����� 10% ���� �������������� 10)
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main() {
/*������-������������ ����������*/
long purchaseamount;
int rate;
double profit,saleamount;
/*�������� ���������*/
printf("Give purchase amount :");
purchaseamount=GetLong();
printf("Give rate :");
rate=GetInteger();
/*����������� ��� �������� �������������*/
profit=(rate/100.0)*purchaseamount;
printf("The profit is %g\n",profit);
saleamount=purchaseamount+profit;
printf("The sale amount is %g\n",saleamount);
return 0;
}
