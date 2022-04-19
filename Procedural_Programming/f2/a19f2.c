#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
 double telh;
 int grammaria;
 printf ("Dwse gram CO2/khm :");
 grammaria=GetInteger();
  if (grammaria>=0 && grammaria<=120){
    telh=0.9*grammaria;
  }else if(grammaria<=140){
   telh=1.1*grammaria;
  }else{
   telh=1.7*grammaria;
  }
 printf("To poso plirwmis einai: %g\n",telh);
return 0;
}
