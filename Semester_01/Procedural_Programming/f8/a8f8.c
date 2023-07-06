/*
File name:a8f8.c

*-----------------------------

    Να γραφεί ένα πρόγραμμα που να περιλαμβάνει μια δομή box, η οποία αναπαριστά ορθογώνια παραλληλεπίπεδα,
    και περιλαμβάνει πέντε ακέραια πεδία: width (πλάτος), height (ύψος), depth (βάθος), area (επιφάνεια)
    και volume (όγκος). Το πρόγραμμα θα περιλαμβάνει τις παρακάτω συναρτήσεις:
    - Μια συνάρτηση που να ζητά από το χρήστη τις διαστάσεις του κουτιού σε cm (μη-αρνητικοί ακέραιοι –
    δεν απαιτείται έλεγχος), δηλαδή το πλάτος, ύψος και βάθος (width, height, depth) και θα επιστρέφει
    δομή box με τα αντίστοιχα τρία πεδία συμπληρωμένα.
    - Μια void συνάρτηση που να υπολογίζει το συνολικό εμβαδόν όλων των πλευρών του κουτιού (πεδίο area).
    H συνάρτηση θα ενημερώνει το αντίστοιχο πεδίο της δομής.
    - Μια void συνάρτηση που να υπολογίζει τον όγκο (πεδίο volume) του κουτιού. H συνάρτηση θα ενημερώνει
    το αντίστοιχο πεδίο της δομής.
    - Οι δύο παραπάνω τιμές (area και volume) θα τυπώνονται από τη συνάρτηση main.
    Και οι τρεις συναρτήσεις να δέχονται ως παράμετρο έναν δείκτη στη δομή box.
*/
#include <stdio.h>
#include "simpio.h"
#define N 10

typedef struct{
   int width;
   int height;
   int depth;
   int area;
   int volume;
}boxT;

void readData(boxT *b);
void calc_area(boxT *b);
void  calc_volume(boxT *b );

int main(){

boxT b;

readData(&b);
calc_area(&b);
calc_volume(&b);
printf("To emvadon tou koutiou einai %d cm2\n",b.area);
printf("O ogos tou koutiou einai %d cm3\n",b.volume);

return 0;
}


/* Ανάγνωση διαστάσεων δοχείου*/
void readData( boxT *b){
  printf("Dose to mikos tou koutiou se cm: ");
  b->width=GetInteger();
  printf("Dose to ypsos tou koutiou se cm: ");
  b->height=GetInteger();
  printf("Dose to vathos tou koutiou se cm: ");
  b->depth=GetInteger();
}

/* Υπολογισμός συνολικού εμβαδού */
void calc_area( boxT *b){
b->area=2*(b->width*b->height+b->width*b->depth+b->height*b->depth);
}

/* Υπολογισμος όγκου */
void calc_volume(boxT *b){
b->volume=b->width*b->height*b->depth;

}

