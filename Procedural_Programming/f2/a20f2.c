#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
 int arithmos;
 printf("Dwse enan arithmo apo to 1 ews to 7: ");
 arithmos=GetInteger();
  switch(arithmos){
   case 1:
    printf("The day is Monday");
    break;
   case 2:
    printf("The day is Tuesday");
    break;
   case 3:
    printf("The day is Wednesday");
    break;
   case 4:
     printf("The day is Thursday");
     break;
   case 5:
    printf("The day is Friday");
    break;
   case 6:
    printf("The day is Saturday");
    break;
   case 7:
    printf("The day is Sunday");
    break;
   default:
    printf("ERROR");
    break;
  }
return 0;
}
