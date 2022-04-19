/*
File:a14f1.c
    Να γραφεί πρόγραμμα που θα υπολογίζει και θα εμφανίζει πόσες θερμίδες χρειάζεται καθημερινά μια γυναίκα
    η οποία κάνει καθιστική ζωή.
    Η ενέργεια που απαιτείται για το βασικό μεταβολισμό του γυναικείου οργανισμού, BMR, υπολογίζεται ως εξής:
    BMR = 655 + (9.6 X Βάρος σε κιλά) + (1.8 X Ύψος σε cm) - (4.7 X Ηλικία σε χρόνια).
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
int main(){
  /*Δήλωση και αρχικοποίηση μεταβλητών*/
  int varos,upsos,ilikia;
  double BMR ;
  /*Εισαγωγή δεδομένων*/
  printf("Dwse to varos se kila :");
  varos=GetInteger();
  printf("Dwse to upsos se cm :");
  upsos=GetInteger();
  printf("Dwse thn ilikia se xronia :");
  ilikia=GetInteger();
  /*Υπολογισμός και εκτύπωση αποτελέσματος*/
  BMR=655+(9.6*varos)+(1.8*upsos)-(4.7*ilikia);
  printf("To BMR einai %g\n",BMR);
  return 0 ;
}
