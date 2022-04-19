#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

long encode(long arxikos_kod);
bool check(long telikos_kod);

int main(){
long telikos_kod,kodikos,ano_orio,j;
printf ("Lower limit :");
kodikos=GetLong();
printf("Upper limit :");
ano_orio=GetLong();
   telikos_kod=encode(j);
    if(check(telikos_kod)==TRUE){
        for(j=kodikos;j<=ano_orio;j++){
        printf("Code: %ld Encoding: %ld isValid:yes\n",j,encode(j));
    }
 }
return 0;}

long encode(long j){
long digits,telikos_kod;
digits=(98-(j*100)%97)%97;
telikos_kod=j*100+digits;
return telikos_kod;}

bool check(long telikos_kod){
long ypoloipo;
ypoloipo=telikos_kod%97;
if(ypoloipo==1){
    return TRUE;
}else{
    return FALSE;
}
}
