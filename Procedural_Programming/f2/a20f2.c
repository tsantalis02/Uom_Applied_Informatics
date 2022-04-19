/*
File:a20f2.c
    Να γραφεί ένα πρόγραμμα στο οποίο θα εισάγουμε έναν τυχαίο αριθμό (int) από το 1 έως το 7
    και ανάλογα θα τυπώνει την αντίστοιχη μέρα της εβδομάδας. Η πρώτη μέρα της εβδομάδας (1) είναι η Δευτέρα (Monday).
    Τα ονόματα των ημερών θα εμφανίζονται στα Αγγλικά (Monday, Tuesday, ... Sunday). Σε περίπτωση μη έγκυρου αριθμού
    ημέρας θα εμφανίζεται το μήνυμα "ERROR".
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
 /*Δήλωση-Αρχικοποίηση μεταβλητών*/
 int arithmos;
 /*Εισαγωγή δεδομένων*/ 
  printf("Dwse enan arithmo apo to 1 ews to 7: ");
  arithmos=GetInteger();
 /*Εκτύπωση αποτελεσμάτων ανάλογα με τον αριθμό που εισήχθη*/
  switch(arithmos){
   case 1:
    printf("The day is Monday");
    break;
   case 2:
    printf("The day is Tuesday");
    break;
   case 3:
    printf("The day is Wednesday");
    break;
   case 4:
     printf("The day is Thursday");
     break;
   case 5:
    printf("The day is Friday");
    break;
   case 6:
    printf("The day is Saturday");
    break;
   case 7:
    printf("The day is Sunday");
    break;
   default:
    printf("ERROR");
    break;
  }
  return 0;
}
