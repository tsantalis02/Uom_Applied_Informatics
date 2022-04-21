/*
File:a10f8.c

Άδεια χρήσης: GNU General Public License v3.0

    Σε ένα ημερολόγιο ενός έργου καταγράφονται διάφορα πακέτα εργασίας. Κάθε εργασία έχει όνομα name
    (char name [60]), μήνα έναρξης (int) όπως μετράται από την αρχή του έργου και διάρκεια σε μήνες
    (int). Για παράδειγμα:
    • η εργασία “project specifications” έχει χρόνο έναρξης 0 (ξεκινά τον πρώτο μήνα του έργου) και
    διάρκεια 4 μήνες, οπότε θεωρείται ότι ολοκληρώνεται τον 4 μήνα.
    • η εργασία “implementation” έχει χρόνο έναρξης 2 και διάρκεια 8 μήνες, οπότε θεωρείται ότι
    ολοκληρώνεται τον 10 μήνα (10 = 8 + 2)
    (α) Να ορίσετε κατάλληλη δομή (νέο τύπο) η οποία να αποθηκεύει τα στοιχεία των εργασιών.
    (β) Να ορίσετε ένα πρόγραμμα το οποίο:
    • Zητά από τον χρήστη τον συνολικό αριθμό εργασιών του έργου WP
    • Mέσω μιας συνάρτησης ReadWorkpackages ζητά από τον χρήστη τα στοιχεία των WP εργασιών
    (όνομα, χρόνο έναρξης και διάρκεια)
    • Βρίσκει ποια εργασία ξεκινά πρώτη μέσω της συνάρτησης FindFirstWp, η οποία επιστρέφει την
    δομή της πρώτης χρονικά εργασίας.
    • Τυπώνει τα στοιχεία της πρώτης χρονικά εργασίας στην οθόνη μέσω της συνάρτησης main().
    • Βρίσκει την συνολική διάρκεια του έργου (makespan) μέσω της συνάρτησης FindMakespan. Η
    συνολική διάρκεια του έργου ορίζεται ως ο μήνας στον οποίο ολοκληρώνεται η τελευταία εργασία
    (έχουν τελειώσει όλες οι εργασίες).
    • Εμφανίζει την συνολική διάρκεια του έργου στην οθόνη.
    Για να γίνουν τα παραπάνω θα πρέπει να ορίσετε κατάλληλο πίνακα δομών με μέγεθος τουλάχιστον 100.
    Θεωρείστε ότι ο χρήστης (α) δεν θα εισάγει περισσότερες από 100 εργασίες (δεν απαιτείται έλεγχος),
    (β) θα εισάγει πάντα ως χρόνο έναρξης ένα μη-αρνητικό ακέραιο (δεν απαιτείται έλεγχος)
    (γ) ότι θα εισάγει πάντα ως διάρκεια ένα θετικό ακέραιο (δεν απαιτείται έλεγχος) και
    (δ) τα ονόματα των εργασιών είναι αυστηρά μικρότερα των 60 χαρακτήρων (δεν απαιτείται έλεγχος).
*/
#include <stdio.h>
#include "simpio.h"
#include <string.h>
#define PACKAGES 100

typedef struct{
  char name[60];
  int start_month;
  int duration;
}workP;

void ReadWorkpackages(workP pack[],int n);
void FindFirstWp(workP pack[],int n,char *first,int *from,int *to);
int FindMakespan(workP pack[],int n);

int main(){
 workP pack[PACKAGES];
 int n,makespan,start,last;
 char first_name[60];
 printf("Total work packages: ");
 n=GetInteger();
 ReadWorkpackages(pack,n);
 FindFirstWp(pack,n,&first_name,&start,&last);
 printf("FIRST WP: %s start: %d duration: %d\n",first_name,start,last);
 makespan=FindMakespan(pack,n);
 printf("Total duration = %d\n",makespan);
 return 0;
}

/* Ανάγνωση στοιχείων εργασίας */
void ReadWorkpackages(workP pack[],int n){
 int i;
 for(i=0;i<n;i++){
    printf("WP Name:");
    gets(pack[i].name);
    printf("WP Start Month:");
    pack[i].start_month=GetInteger();
    printf("WP Duration:");
    pack[i].duration=GetInteger();
 }
}

/* Εύρεση εργασίας που εκκινεί πρώτη */
void FindFirstWp(workP pack[],int n,char *first,int *from,int *to ){
 int i,min;
 min=pack[0].start_month;
 strcpy(first,pack[0].name);
 *to=pack[0].duration;
  for(i=1;i<n;i++){
    if(pack[i].start_month<min){
        min=pack[i].start_month;
        strcpy(first,pack[i].name);
        *to=pack[i].duration;
    }
 }
 *from=min;
}

/* Εύρεση συνολικής διάρκειας έργου */
int FindMakespan(workP pack[],int n){
 int i,make;
 make=pack[0].duration+pack[0].start_month;
 for(i=1;i<n;i++){
   if( make<pack[i].duration+pack[i].start_month){
     make=pack[i].duration+pack[i].start_month;
   }
 }
 return make;
}
