#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
int main() {
int wres;
long antimisthia;
double pososto_krathsewn,akatharistes,krathseis,kathares;
printf("Dwse ton arithmo twn wrwn :");
wres=GetInteger();
printf("Dwse thn wriaia antimisthia :");
antimisthia=GetLong();
printf("Dwse to pososto twn krathsewn :");
pososto_krathsewn=GetReal() ;
kathares=wres*antimisthia ;
krathseis=kathares*pososto_krathsewn ;
akatharistes=kathares+krathseis ;
printf("Oi akatharistes apodoxes einai %g\n",akatharistes);
printf("Oi krathseis einai %g\n",krathseis);
printf("Oi kathares apodoxes einai %g\n",kathares);
return 0 ;
}
