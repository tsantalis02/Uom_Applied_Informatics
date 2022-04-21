/*
File:a20f3.c

Άδεια χρήσης: GNU General Public License v3.0

Γράψτε ένα πρόγραμμα που να διαβάζει μια σειρά από ηλικίες ανθρώπων (ακολουθία αριθμών int που εισάγεται από το χρήστη)
και να βρίσκει την μικρότερη και τη μεγαλύτερη ηλικία. Το πρόγραμμα θα συνεχίζει να διαβάζει ηλικίες μέχρι να δοθεί ως ηλικία
ο αριθμός -1
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int main(){
/*Δήλωση-Αρχικοποίηση μεταβλητών*/
 int ilikia,max,min;
/*Εισαγωγή δεδομένων*/ 
 printf("Dwse ilikia: ");
 ilikia=GetInteger();
 if (ilikia>=0){
    max=ilikia; /* Θέτουμε ως μέγιστη ηλικία, τον αριθμό που εισήχθη από τον χρήστη */
    min=ilikia; /* Θέτουμε ως ελάχιστη ηλικία, τον αριθμό που εισήχθη από τον χρήστη */
 }
 /*Υπολογισμοί*/
 while(ilikia>=0){
    printf("Dwse ilikia: ");
    ilikia=GetInteger();
     if (ilikia>max){
        max=ilikia;
     }
     if (ilikia!=-1){
       if(ilikia<min){
        min=ilikia;
       }
     }
 }
  /*Εκτύπωση αποτελεσμάτων*/
  printf("H megalyteri ilikia einai %d\n",max);
  printf("H mikroteri ilikia einai  %d\n",min);
  return 0;
}
