/*
File:a1bf3.c

Άδεια χρήσης: GNU General Public License v3.0

 Να γράψετε πρόγραμμα για κάθε μία από τις παρακάτω περιπτώσεις:
    a. Ο σημερινός αριθμός αυτοκινήτων που κυκλοφορούν σε μια πόλη είναι 80000. Αν ο αριθμός αυτός αυξάνεται με ρυθμό 7%,
    να γραφεί πρόγραμμα που να υπολογίζει σε πόσα χρόνια ο αριθμός των αυτοκινήτων θα ξεπεράσει τις 160000.
    Πόσα θα είναι τότε τα αυτοκίνητα;
    b. Γενικεύστε το πρόγραμμα για Αrithmo_Αytok (long) αυτοκίνητα, που αυξάνονται με ετήσιο ρυθμό Rythmos και ξεπερνούν
    ένα δοσμένο όριο Οrio (long), στοιχεία τα οποία θα εισάγει ο χρήστης.
    Τα προγράμματα a και b να εμφανίζουν τα έτη (long) και τον αριθμό των αυτοκινήτων (long) όταν θα ξεπεράσει το δοσμένο όριο.
    Για τον υπολογισμό του ετήσιου αριθμού αυτοκινήτων να χρησιμοποιηθεί ο τύπος:
	Αριθμός αυτοκινήτων = ceil(Αριθμός αυτοκινήτων *(1+Ρυθμός αύξησης))
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int main(){
  /*Δήλωση-Αρχικοποίηση μεταβλητών*/
  long Arithmo_Aytok,Orio,years;
  double Rythmos;
 /*Εισαγωγή δεδομένων*/
  printf("Dwse ton arxilko arithmo  aytokinitwn :");
  Arithmo_Aytok=GetLong();
  printf("Dwse ton ethsio rythmo ayxhshs :");
  Rythmos=GetReal();
  printf("Dwse to orio :");
  Orio=GetLong();
  years=0;
 /*Υπολογισμοί*/
  while(Arithmo_Aytok<=Orio){
    Arithmo_Aytok=ceil(Arithmo_Aytok*(1+Rythmos));
    years=years+1;
  }
 /*Εκτύπωση αποτελεσμάτων*/
  printf("%ld\n",years);
  printf("%ld\n",Arithmo_Aytok);
  return 0;
}
