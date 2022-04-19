/*
File:a13f2.c
    Μία μηχανή αυτόματης πώλησης καφέ δέχεται μόνο ΕΝΑ χαρτονόμισμα των 5 € κάθε φορά και δίνει τα ρέστα σε κέρματα
    των 10, 20 & 50 λεπτών καθώς και σε κέρματα του 1 και 2 ευρώ . Κάθε καφές κοστίζει 70 λεπτά.
    Να γραφεί πρόγραμμα το οποίο να ζητάει τον αριθμό των καφέδων (int) και να εμφανίζει τα ρέστα (σε κέρματα) (int)
    που πρέπει να δώσει από το χαρτονόμισμα των 5€. Στην περίπτωση που τα χρήματα δεν επαρκούν εμφανίζει το κατάλληλο μήνυμα.
    (Τα χρήματα υπολογίζονται σε λεπτά του ευρώ).
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main(){
 /*Δήλωση και αρχικοποίηση μεταβλητών*/
  int kafedes,kostos,x,y,z,n,m,ypoloipo;
 /*Εισαγωγή δεδομένων*/
  printf("Dwse kafedes :");
  kafedes=GetInteger();
 /*Υπολογισμοί και εκτύπωση αποτελέσματος*/ 
  kostos=kafedes*70;
  if (kostos>500){
    printf("Den ftanoun ta xrhmata gia tosous kafedes");
  }else{
   ypoloipo=500-kostos;
   x=ypoloipo/200;
   ypoloipo=ypoloipo%200;
   y=ypoloipo/100;
   ypoloipo=ypoloipo%100;
   z=ypoloipo/50;
   ypoloipo=ypoloipo%50;
   n=ypoloipo/20;
   ypoloipo=ypoloipo%20;
   m=ypoloipo/10;
   ypoloipo=ypoloipo%10;
   printf("Resta \n");
   printf("Kermata 2E :%d\n",x);
   printf("Kermata 1E :%d\n",y);
   printf("Kermata 50L :%d\n",z);
   printf("Kermata 20L :%d\n",n);
   printf("Kermata 10L :%d\n",m);
  }
 
  return 0;
}
