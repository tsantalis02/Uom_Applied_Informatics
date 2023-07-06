/*
File name:a23f4.c

*------------------------

������ ��������� ��� ������������ ��� ��������� �� �� ����� Valid_Time � ����� �� ������� �� ������� �����������
    3 ��������� �������� (int) ��� ������������ �� ����, ����� ��� ������������ ���� �������� ������� ��� ������ (���)
    ��� �� ���������� ��� ���� �RU� � F�LS� ������� �� �� �� � ������� ������� ������ (���) ����� ������ � ���
    (�� ������ �� ���� �� ������ �� ����� ��� 0 ��� ��� 23 ��� �� ����� ��� ������������ �� ����� ��� 0 ��� ��� 59).
    �� �������� (����, ����� ��� ������������) �� ��������� ��� ��� ������ ��� ������ ���������, ���� �������� ��� �������� ������������.
    ��� ����� �� ��������� �� ��������� �� ������ �WRA EGKYRH� � �WRA MH EGKYRH� ��� �� ������ ��������� (��������� main(), ������ � ������
    ��������� ��� ��������� (printf) �� ����� ���� main).
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

 bool Valid_Time(int h,int min,int sec);

int main(){
int h,min,sec;
printf("Dwse tis wres :");
h=GetInteger();
printf ("Dwse ta lepta:");
min=GetInteger();
printf("Dwse ta deyterolepta:");
sec=GetInteger();
 if(Valid_Time(h,min,sec)){
    printf("WRA EGKYRH");
 }else{
   printf("WRA MH EGKYRH");
 }
return 0;
}
bool Valid_Time(int h,int min,int sec){
return (((h>=0) && (h<=23)) && ((min>=0) && (min<=59)) && ((sec>=0) && (sec<=59)));
/*    if ((hour>=0 && hour<23) && (min>=0 && min<59) && (sec>=0 && sec<59))
    { return TRUE;
    }
    else
    { return FALSE;
    }
    */
}
