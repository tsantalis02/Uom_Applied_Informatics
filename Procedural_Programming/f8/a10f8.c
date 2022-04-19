#include <stdio.h>
#include "simpio.h"
#include <string.h>
#define PACKAGES 100

typedef struct{
  char name[60];
  int start_month;
  int duration;
}workP;

void ReadWorkpackages(workP pack[],int n);
void FindFirstWp(workP pack[],int n,char *first,int *from,int *to);
int FindMakespan(workP pack[],int n);

int main(){
workP pack[PACKAGES];
int n,makespan,start,last;
char first_name[60];
printf("Total work packages: ");
n=GetInteger();
ReadWorkpackages(pack,n);
FindFirstWp(pack,n,&first_name,&start,&last);
printf("FIRST WP: %s start: %d duration: %d\n",first_name,start,last);
makespan=FindMakespan(pack,n);
printf("Total duration = %d\n",makespan);
return 0;
}

void ReadWorkpackages(workP pack[],int n){
 int i;
 for(i=0;i<n;i++){
    printf("WP Name:");
    gets(pack[i].name);
    printf("WP Start Month:");
    pack[i].start_month=GetInteger();
    printf("WP Duration:");
    pack[i].duration=GetInteger();
 }
}

void FindFirstWp(workP pack[],int n,char *first,int *from,int *to ){
int i,min;
min=pack[0].start_month;
strcpy(first,pack[0].name);
*to=pack[0].duration;
 for(i=1;i<n;i++){
    if(pack[i].start_month<min){
        min=pack[i].start_month;
        strcpy(first,pack[i].name);
        *to=pack[i].duration;
    }
 }
 *from=min;
}

int FindMakespan(workP pack[],int n){
int i,make;
make=pack[0].duration+pack[0].start_month;
 for(i=1;i<n;i++){
   if( make<pack[i].duration+pack[i].start_month){
     make=pack[i].duration+pack[i].start_month;
   }
 }
return make;
}
