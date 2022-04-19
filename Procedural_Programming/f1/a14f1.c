#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
int main(){
int varos,upsos,ilikia;
double BMR ;
printf("Dwse to varos se kila :");
varos=GetInteger();
printf("Dwse to upsos se cm :");
upsos=GetInteger();
printf("Dwse thn ilikia se xronia :");
ilikia=GetInteger();
BMR=655+(9.6*varos)+(1.8*upsos)-(4.7*ilikia);
printf("To BMR einai %g\n",BMR);
return 0 ;
}
