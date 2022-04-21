/*
*File name:a4f1.c
*------------------------
Άδεια χρήσης: GNU General Public License v3.0
Ένας έμπορος αγόρασε σε τιμή χονδρικής εμπορεύματα αξίας purchaseAmount € και τα πούλησε saleAmount €.
    Αν το ποσό saleAmount προκύπτει από την καθαρή αξία purchaseAmount και το ποσοστό κέρδους rate
    του εμπόρου επί της καθαρής αξίας purchaseAmount, να γίνει πρόγραμμα που να υπολογίζει και να εμφανίζει:
    α) το κέρδος του εμπόρου profit (double),
    β) το εισπραχθέν ποσό saleAmount (double).
    Τα δεδομένα εισόδου να έχουν τη μορφή:
    purchaseAmount (μεταβλητή τύπου long)
    rate (μεταβλητή τύπου int, εάν το ποσοστό κέρδους είναι 10% τότε πληκτρολογούμε 10)
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main() {
 /*Δήλωση-Αρχικοποίηση μεταβλητών*/
 long purchaseamount;
 int rate;
 double profit,saleamount;
  /*Εισαγωγή δεδομένων*/
  printf("Give purchase amount :");
  purchaseamount=GetLong();
  printf("Give rate :");
  rate=GetInteger();
  /*Υπολογισμός και εκτύπωση αποτελεσμάτων*/
  profit=(rate/100.0)*purchaseamount;
  printf("The profit is %g\n",profit);
  saleamount=purchaseamount+profit;
  printf("The sale amount is %g\n",saleamount);
  return 0;
}
