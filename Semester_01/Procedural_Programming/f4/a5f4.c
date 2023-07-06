/*
File name:a5f4.c

*---------------------------

    Οι αριθμοί για τους οποίους το άθροισμα των κύβων των ψηφίων τους είναι ίσο με τον ίδιο τον αριθμό λέγονται αριθμοί Αrmstrong
    (π.χ. 153 = 1^3 +5^3 +3^3 ). Να γραφεί πρόγραμμα που θα περιλαμβάνει τα παρακάτω:
    1) την συνάρτηση Sum_Cube που θα δέχεται έναν ακέραιο αριθμό (μεταξύ του 1 και του 999) και θα επιστρέφει το άθροισμα των κύβων
    των ψηφίων του.
    2) την συνάρτηση IsArmstrong που θα δέχεται έναν ακέραιο αριθμό και θα επιστρέφει την τιμή TRUE ή FALSE ανάλογα με το αν ο αριθμός
    είναι Αrmstrong ή όχι αντίστοιχα.
    Το κυρίως πρόγραμμα θα βρίσκει και θα εμφανίζει ποιοι είναι αριθμοί Αrmstrong στο διάστημα (1-999).
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int cube (int digit);
bool IsArmstrong(int number); // Δήλωση συνάρτησης IsArmstrong
int sum_cube(int number);// Δήλωση συνάρτησης Sum_Cube 

int main (){
int k;
 //printf("Dwse arithmo:");
 //number=GetInteger();
 for(k=1;k<1000;k++){
if(IsArmstrong(k)){// Έλεγχος εάν είναι TRUE ή FALSE
    printf("%d is an Armstrong number\n",k);// Εκτύπωση του k
}
 }
return 0;
}


int cube(int digit){
 int i,gin;
 gin=1;
 for(i=0;i<3;i++){
    gin *=digit;
 }
return gin;
}

bool IsArmstrong(int number){
return(number==sum_cube(number));
}// Συγκρίνει αν το number είναι ίσο με το άθροισμα των ψηφίων υψωμένων στον κύβο (συνάρτηση Sum_Cube)

int sum_cube(int number){
 int sum=0;
 while(number>0){
    sum+=cube(number%10);
    number/=10;
}
return sum;
}
