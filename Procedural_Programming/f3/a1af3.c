#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

#define rate 0.07
#define limit 160000

int main () {
long cars,years;
cars=80000;
years=0;
 while (cars<=limit){
    cars=ceil(cars*(1+rate));
    years=years+1;
 }
printf ("%ld\n",years);
printf ("%ld\n",cars);
return 0;
}
