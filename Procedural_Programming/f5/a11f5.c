#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

#define rows 10
#define cols 3

int main(){
double temper[rows][cols],natavg,average[rows],devnat[rows][cols],mdev[rows];
int i,j;
for (i=0;i<rows;i++){
    for(j=0;j<cols;j++){
        printf("Temp of City %d During %d 8-hour period:",i,j);
        temper[i][j]=GetReal();
    }
}

natavg=0;
for (i=0;i<rows;i++){
    for (j=0;j<cols;j++){
        natavg+=temper[i][j];
    }
}
natavg/=(rows*cols);

for(i=0;i<rows;i++){
    average[i]=0;
    for(j=0;j<cols;j++){
        average[i]+=temper[i][j];
    }
    average[i]/=cols;
}
for (i=0;i<rows;i++){
    for(j=0;j<cols;j++){
        devnat[i][j]=fabs(natavg-temper[i][j]);
    }
}

for(i=0;i<rows;i++){
   mdev[i]=devnat[i][0];
    for(j=0;j<cols;j++){
        if(devnat[i][j]>mdev[i]){
            mdev[i]=devnat[i][j];
        }
    }
}
printf("%3.1f\n", natavg);
for(i=0;i<rows;i++){
    printf("City %d %.1f %.1f\n",i,average[i],mdev[i]);
}
return 0;}
