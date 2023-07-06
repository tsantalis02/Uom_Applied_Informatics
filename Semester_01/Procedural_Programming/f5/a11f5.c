/*
File:a11f5.c

*--------------------

*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

#define rows 10 //cities
#define cols 3  //temperatures

int main(){
double temper[rows][cols],natavg,average[rows],devnat[rows][cols],mdev[rows];
int i,j;
/* Read 3 temperatures for 10 cities */
for (i=0;i<rows;i++){
    for(j=0;j<cols;j++){
        printf("Temp of City %d During %d 8-hour period:",i,j);
        temper[i][j]=GetReal();
    }
}
/* Calculate the average of all cities & temperatures*/
natavg=0;
for (i=0;i<rows;i++){
    for (j=0;j<cols;j++){
        natavg+=temper[i][j];
    }
}
natavg/=(rows*cols);

/* Calculate city average*/
for(i=0;i<rows;i++){
    average[i]=0;
    for(j=0;j<cols;j++){
        average[i]+=temper[i][j];
    }
    average[i]/=cols;
}

/* Calculating standard deviation*/
for (i=0;i<rows;i++){
    for(j=0;j<cols;j++){
        devnat[i][j]=fabs(natavg-temper[i][j]);
    }
}

/* Calculating max deviation */
for(i=0;i<rows;i++){
   mdev[i]=devnat[i][0];
    for(j=0;j<cols;j++){
        if(devnat[i][j]>mdev[i]){
            mdev[i]=devnat[i][j];
        }
    }
}

/* Printing results*/
printf("%3.1f\n", natavg);
for(i=0;i<rows;i++){
    printf("City %d %.1f %.1f\n",i,average[i],mdev[i]);
}
return 0;}
