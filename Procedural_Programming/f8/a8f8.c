#include <stdio.h>
#include "simpio.h"
#define N 10

typedef struct{
   int width;
   int height;
   int depth;
   int area;
   int volume;
}boxT;

void readData(boxT *b);
void calc_area(boxT *b);
void  calc_volume(boxT *b );

int main(){

boxT b;

readData(&b);
calc_area(&b);
calc_volume(&b);
printf("To emvadon tou koutiou einai %d cm2\n",b.area);
printf("O ogos tou koutiou einai %d cm3\n",b.volume);

return 0;
}



void readData( boxT *b){
  printf("Dose to mikos tou koutiou se cm: ");
  b->width=GetInteger();
  printf("Dose to ypsos tou koutiou se cm: ");
  b->height=GetInteger();
  printf("Dose to vathos tou koutiou se cm: ");
  b->depth=GetInteger();
}


void calc_area( boxT *b){
b->area=2*(b->width*b->height+b->width*b->depth+b->height*b->depth);
}


void calc_volume(boxT *b){
b->volume=b->width*b->height*b->depth;

}

