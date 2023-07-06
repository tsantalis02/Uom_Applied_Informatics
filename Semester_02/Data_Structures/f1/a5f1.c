/*
File:a5f1.c

Άδεια χρήσης: GNU General Public License v3.0
    
    Στα μαθηματικά, η ακολουθία Fibonacci ορίζεται ως το σύνολο των αριθμών που προκύπτουν από το
    άθροισμα των δύο προηγούμενων αριθμών του συνόλου. Εξ ορισμού, οι 2 πρώτοι αριθμοί του συνόλου είναι
    οι 0,1. Να γραφεί πρόγραμμα το οποίο θα υλοποιεί τις παρακάτω συναρτήσεις:
    a. Συνάρτηση isFibonacci, η οποία δέχεται έναν θετικό ακέραιο n και μία ακολουθία Fibonacci
    (typos_synolou) και επιστρέφει την τιμή TRUE ή FALSE ανάλογα εάν ο αριθμός ανήκει ή όχι
    αντίστοιχα στην ακολουθία Fibonacci
    b. Διαδικασία createFibonacciSet η οποία θα δέχεται έναν θετικό ακέραιο threshold και θα δημιουργεί
    και επιστρέφει το σύνολο Fibonacci, μέχρι και τον αριθμό που είναι μικρότερος ή ίσος από τον
    δοσμένο ακέραιο.
    Στη συνέχεια, γράψτε κυρίως πρόγραμμα το οποίο θα ζητάει από τον χρήστη έναν ακέραιο αριθμό max, ο
    οποίος ανήκει στο διάστημα [2...1000] και θα δημιουργεί και θα εμφανίζει την ακολουθία Fibonacci, όπου
    το μεγαλύτερο στοιχείο της θα είναι μικρότερο ή ίσο του max. Χρησιμοποιείστε την υλοποίηση ΑΔΤ
    σύνολο με πίνακα και τη διαδικασία displaySet από το TestSetADT.c για την εμφάνιση του συνόλου.
    Τέλος, μετά την εμφάνιση του συνόλου, ο χρήστης θα μπορεί να εισάγει αριθμούς επανηληπτικά, τους
    οποίους το πρόγραμμα θα ελέγχει για το εάν ανήκουν στην τρέχουσα ακολουθία Fibonacci και θα εκτυπώνει
    αντίστοιχο μήνυμα Το πρόγραμμα θα τερματίζει όταν λάβει αρνητικό αριθμό.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define plithos 1001

typedef enum{
  FALSE,TRUE
}boolean;

typedef boolean typos_synolou[plithos];
typedef int stoixeio;

boolean isFibonacci(stoixeio n,typos_synolou F);
void createFibonacciSet(stoixeio threshold,typos_synolou F);
void displaySet(typos_synolou F,stoixeio threshold);
boolean Melos(stoixeio n,typos_synolou F);
void Eisagogi(stoixeio ,typos_synolou F);
void Dimiourgia(typos_synolou F);

int main(){
 stoixeio max,number;
 typos_synolou F; 
 printf("Dwse to megisto arithmo. ");
 scanf("%d",&max);
//Έλεγχος αν ο μέγιστος όρος βρίσκεται στο διάστημα [2,1000]  
 while(max<2 || max>1000){
    printf("Dwse to megisto arithmo. ");
    scanf("%d",&max);
 }
 /*ΕΝΝΑΛΑΚΤΙΚΗ
  while(TRUE){
        printf("Dwse to megisto arithmo. ");
        scanf("%d", &max);
        if(max>=2 && max<=1000) {break;}
        printf("O megistos arithmos prepei na anhkei sto diasthma [2...1000]\n");
   }
 */
 createFibonacciSet(max,F);  // Δημιουργεί το σύνολο με όρους fibonacci μέχρι τον όρο max που έχει δοθεί
 displaySet(F,max); // Εμφανίζει όλους τους όρους του συνόλου
 printf("Enter number to check:");
 scanf("%d",&number);
/* Έλεγχος εάν ο αριθμός που εισάγουμε είναι όρος fibonacci ή όχι */  
 while(number!=-1){
    if(isFibonacci(number,F)){
        printf("Fibonacci!\n");
    }else{
       printf("Not Fibonacci...\n");
    }
    printf("Enter number to check:");
    scanf("%d",&number);
    if(number==-1)
    {
        system("PAUSE");
    }
}
 return 0;
}

void createFibonacciSet(stoixeio threshold,typos_synolou F){
 stoixeio temp1,temp2,sum;
 Dimiourgia(F); // Δημιουργία συνόλου
 temp2=0;
 Eisagogi(temp2,F); // Εισάγει τον πρώτο όρο
 temp1=1;
 Eisagogi(temp1,F); // Εισάγει τον δεύτερο όρο
 do{
  if(temp2==0){
    temp2=temp1;
    temp1=2;
    Eisagogi(temp1,F);
    sum=temp1;
  }else{
    sum=temp1+temp2;
    if(sum<=threshold)
    {
    Eisagogi(sum,F);
    }
    temp2=temp1;
    temp1=sum;
  }
 }while(sum<=threshold);
}

void displaySet(typos_synolou F,stoixeio threshold){
 stoixeio i;
 for(i=0;i<plithos;i++){
    if(Melos(i,F)){
        printf(" %d",i);
    }
 }
 printf("\n");
}

boolean isFibonacci(stoixeio n,typos_synolou F)
{
 return (Melos(n,F)); // Επιστρέφει εάν ανήκει στο σύνολο των όρων fibonacci που έχουμε δημιουργήσει με την createFibonacciSet
}

boolean Melos(stoixeio n,typos_synolou F)
{
 return F[n];
}

void Dimiourgia(typos_synolou F)
{
 stoixeio i;
     for (i = 0; i < plithos; i++)
        F[i] = FALSE;
}

void Eisagogi(stoixeio n,typos_synolou F)
{
 F[n]=TRUE;
}
