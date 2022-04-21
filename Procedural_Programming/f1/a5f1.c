/*
File:a5f1.c

Άδεια χρήσης: GNU General Public License v3.0

    Να γραφεί πρόγραμμα που διαβάζει τις ώρες εργασίας (int), την ωριαία αντιμισθία (long) και το ποσοστό (double)
    των κρατήσεων ενός εργάτη και στη συνέχεια υπολογίζει κι εμφανίζει τις ακαθάριστες αποδοχές του (double),
    το ποσό των κρατήσεων (double) που έχει     και τις καθαρές του αποδοχές (double).
    Ο υπολογισμός των ποσών θα γίνεται ως εξής:
    Καθ. Αποδοχές= ώρες * ωριαία αντιμισθία
    κρατήσεις= καθαρές αποδοχές * ποσοστό
    ακαθάριστες αποδοχές= καθαρές αποδοχές + κρατήσεις
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
int main() {
  /*Δήλωση και αρχικοποίηση μεταβλητών*/
  int wres;
  long antimisthia;
  double pososto_krathsewn,akatharistes,krathseis,kathares;
  /*Εισαγωγή δεδομένων*/
  printf("Dwse ton arithmo twn wrwn :");
  wres=GetInteger();
  printf("Dwse thn wriaia antimisthia :");
  antimisthia=GetLong();
  printf("Dwse to pososto twn krathsewn :");
  pososto_krathsewn=GetReal() ;
  /*Υπολογισμοί*/
  kathares=wres*antimisthia ;
  krathseis=kathares*pososto_krathsewn ;
  akatharistes=kathares+krathseis ;
  /*Εκτύπωση αποτελεσμάτων*/
  printf("Oi akatharistes apodoxes einai %g\n",akatharistes);
  printf("Oi krathseis einai %g\n",krathseis);
  printf("Oi kathares apodoxes einai %g\n",kathares);
  return 0 ;
}
