/*
File name:a23f4.c

*------------------------

Γράψτε πρόγραμμα που περιλαμβάνει μια συνάρτηση με το όνομα Valid_Time η οποία θα δέχεται ως τυπικές παραμέτρους
    3 ακέραιους αριθμούς (int) που αντιστοιχούν σε ώρες, λεπτά και δευτερόλεπτα μιας χρονικής στιγμής της ημέρας (ώρα)
    και θα επιστρέφει την τιμή ΤRUΕ ή FΑLSΕ ανάλογα με το αν η δοθείσα χρονική στιγμή (ώρα) είναι έγκυρη ή όχι
    (αν δηλαδή οι ώρες θα πρέπει να είναι από 0 έως και 23 και τα λεπτά και δευτερόλεπτα να είναι από 0 έως και 59).
    Τα δεδομένα (ώρες, λεπτά και δευτερόλεπτα) θα ζητούνται από τον χρήστη στο κυρίως πρόγραμμα, όπως φαίνεται στα ακόλουθα παραδείγματα.
    Στο τέλος το πρόγραμμα θα εμφανίζει το μήνυμα “WRA EGKYRH” ή “WRA MH EGKYRH” από το κυρίως πρόγραμμα (συνάρτηση main(), δηλαδή η εντολή
    εμφάνισης του μηνύματος (printf) θα είναι στην main).
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

 bool Valid_Time(int h,int min,int sec);

int main(){
int h,min,sec;
printf("Dwse tis wres :");
h=GetInteger();
printf ("Dwse ta lepta:");
min=GetInteger();
printf("Dwse ta deyterolepta:");
sec=GetInteger();
 if(Valid_Time(h,min,sec)){
    printf("WRA EGKYRH");
 }else{
   printf("WRA MH EGKYRH");
 }
return 0;
}
bool Valid_Time(int h,int min,int sec){
return (((h>=0) && (h<=23)) && ((min>=0) && (min<=59)) && ((sec>=0) && (sec<=59)));
/*    if ((hour>=0 && hour<23) && (min>=0 && min<59) && (sec>=0 && sec<59))
    { return TRUE;
    }
    else
    { return FALSE;
    }
    */
}
