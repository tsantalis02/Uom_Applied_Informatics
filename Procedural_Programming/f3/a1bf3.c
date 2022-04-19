#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int main(){
long Arithmo_Aytok,Orio,years;
double Rythmos;
printf("Dwse ton arxilko arithmo  aytokinitwn :");
Arithmo_Aytok=GetLong();
printf("Dwse ton ethsio rythmo ayxhshs :");
Rythmos=GetReal();
printf("Dwse to orio :");
Orio=GetLong();
years=0;
 while(Arithmo_Aytok<=Orio){
    Arithmo_Aytok=ceil(Arithmo_Aytok*(1+Rythmos));
    years=years+1;
 }
printf("%ld\n",years);
printf("%ld\n",Arithmo_Aytok);
return 0;
}
