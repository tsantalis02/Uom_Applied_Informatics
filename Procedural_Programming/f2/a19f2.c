/*
File:a19f2.c
   Να γραφεί πρόγραμμα που να υπολογίζει τα τέλη κυκλοφορίας (float) με βάση τις εκπομπές CO2 (γραμμάρια, int) ως εξής:
	    0-120 γρ./χλμ. -> 0,9 ευρώ/γρ.
	    121-140 γρ./χλμ -> 1,1 ευρώ/γρ.
	    > 140 γρ./χλμ. -> 1,7 ευρώ/γρ.
   Η χρέωση ΔΕΝ είναι κλιμακωτή.
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
 /*Δήλωση-Αρχικοποίηση μεταβλητών*/
 double telh;
 int grammaria;
 /*Εισαγωγή δεδομένων*/
 printf ("Dwse gram CO2/khm :");
 grammaria=GetInteger();
 /*Υπολογισμός και εκτύπωση αποτελέσματος*/
  if (grammaria>=0 && grammaria<=120){
    telh=0.9*grammaria;
  }else if(grammaria<=140){
   telh=1.1*grammaria;
  }else{
   telh=1.7*grammaria;
  }
  printf("To poso plirwmis einai: %g\n",telh);
  return 0;
}
