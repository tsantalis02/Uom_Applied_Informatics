/*
File:a20f5.c
    Να γραφεί ένα πρόγραμμα το οποίο να διαβάζει 5 ακεραίους και να τους αποθηκεύει σε έναν πίνακα. Στη
    συνέχεια, το πρόγραμμα να περιστρέφει τα στοιχεία του πίνακα μία θέση δεξιά και θα τυπώνει τον πίνακα
    στην οθόνη. Για παράδειγμα, αν τα στοιχεία του πίνακα είναι: 1, -9, 5, 3, 4 ο πίνακας μετά την περιστροφή
    θα είναι: 4, 1, -9, 5, 3. Η εκτέλεση φαίνεται παρακάτω.

*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

#define N 5 //Numbers


int main(){
 int pinakas[N],i,k;
 /*Read 5 numbers*/
 for(i=0;i<N;i++){
    printf("Enter number:");
    pinakas[i]=GetInteger();
 }
/*Rotate*/
 for(i=N-1;i>0;i--){
    if (i==N-1){
        k=pinakas[i];
    }
    pinakas[i]=pinakas[i-1];
   }
 pinakas[0]=k;
  for(i=0;i<N;i++){
    printf("%d ",pinakas[i]);
 }
 return 0;
}
