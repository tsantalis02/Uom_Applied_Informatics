/*
File:a16f7.c

Άδεια χρήσης: GNU General Public License v3.0

    Να γραφεί ένα πρόγραμμα το οποίο θα δέχεται ένα αλφαριθμητικό μέχρι 99 χαρακτήρες
    (θα δηλώσετε ένα πίνακα 100 χαρακτήρων) και να εμφανίζει τα ψηφία που περιέχονται
    μέσα στο αλφαριθμητικό και το άθροισμά τους, όπως φαίνεται στα παραδείγματα που ακολουθούν.
    Αν δεν υπάρχει ψηφίο, τότε εμφανίζεται το μήνυμα "No digits in input".
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "simpio.h"

#define N 100

void checkDigit(char A[]);

int main(){
 char A[N];
  printf("Insert a string: ");
  gets(A);
  checkDigit(A);
 return 0;
}


void checkDigit(char A[]){
  int i,j=-1,s=-8;
   for(i=0;i<N;i++){
    if(A[i]>='0' && A[i]<='9'){
     s+=(A[i]-48);
     j+=1;
      if(j==0 && A[i]!='8'){
        printf("%d",A[i]-48);
      }else{
        if(A[i]!= '8'){
         printf(" + %d",A[i]-48);
        }
      }
    }
   }
   if(j==-1 || j==0){
    printf("No digits in input. \n");
   }else{
    printf(" = %d \n",s);
   }
}
