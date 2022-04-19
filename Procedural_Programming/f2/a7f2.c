/*
File:a7f2.c
    Να γραφεί ένα πρόγραμμα C για τον υπολογισμό και την εμφάνιση της εβδομαδιαίας αμοιβής ενός εργαζομένου ως εξής:
    Το πρόγραμμα θα διαβάζει τον κωδικό αριθμό (long) του εργαζομένου. Αν ο κωδικός αριθμός είναι μεγαλύτερος ή ίσος του 1000,
    τότε το πρόγραμμα θα διαβάζει τον ετήσιο μισθό του εργαζομένου (double) και θα υπολογίζει την εβδομαδιαία αμοιβή (double)
    του διαιρώντας τον ετήσιο μισθό δια 52.
    Αν ο κωδικός είναι μικρότερος του 1000, τότε το πρόγραμμα θα διαβάζει τις ώρες εβδομαδιαίας εργασίας (int) του εργαζομένου,
    την αμοιβή ανά ώρα (double) και στη συνέχεια θα υπολογίζει την εβδομαδιαία αμοιβή. Αν η εβδομαδιαία εργασία είναι άνω των
    40 ωρών, τότε για τις ώρες πέρα των 40 ωρών η αμοιβή έχει προσαύξηση 50%.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main (){
 /*Δήλωση-Αρχικοποίηση μεταβλητών*/
 long kwdikos;
 int wres;
 double ethsios,ebdomadiaios,amoibhanawra;
 /*Εισαγωγή δεδομένων και υπολογισμοί ανάλογα με την πρώτη εισαγωγή κωδικού*/
  printf("Dwse ton kwdiko toy ergazomenoy :");
  kwdikos=GetLong();
  if (kwdikos >=1000){
   printf("Dwse ton ethsio mistho : ");
   ethsios=GetReal();
   ebdomadiaios=ethsios/52;
  }else{
   printf("Dwse tis wres ebdomadiaias ergasias :");
   wres=GetInteger();
   printf("Dwse thn amoibh ana wra :");
   amoibhanawra=GetReal();
    if (wres>40){
      ebdomadiaios=40*amoibhanawra+1.5*(wres-40)*amoibhanawra;
    }else{
    ebdomadiaios=wres*amoibhanawra;
    }
  }
  /*Εκτύπωση αποτελέσματος*/
  printf("O ebdomadiaios misthos einai %g\n",ebdomadiaios);
  return 0;
}
