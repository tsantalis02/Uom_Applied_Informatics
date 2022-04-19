/*
File:a16f5.c
 Να αναπτυχθεί (με τη χρήση των συναρτήσεων που περιγράφονται) πρόγραμμα στο οποίο,
    - θα γεμίζει τον πίνακα a μεγέθους 50 με τυχαίους αριθμούς από το 0 έως το 9 χρησιμοποιώντας την
    συνάρτηση rand() (a[i]=rand() % 10), της βιβλιοθήκης <stdlib.h> (συνάρτηση populate)
    - θα εμφανίζει τον πίνακα a στην οθόνη (συνάρτηση printArr),
    - θα ζητά έναν ακέραιο αριθμό Ν από το 0 έως και το 9 από τον χρήστη - δεν απαιτείται έλεγχος,
    - θα καλεί την συνάρτηση checkTable, η οποία θα υπολογίζει τον αριθμό των εμφανίσεων του αριθμού Ν στον πίνακα a
    και τις θέσεις του πίνακα στις οποίες εμφανίζεται ο αριθμός
    - θα εμφανίζει τα αποτελέσματα στο χρήστη, όπως φαίνεται στο παράδειγμα εκτέλεσης. Η εμφάνιση των αποτελεσμάτων
    θα γίνεται από τη συνάρτηση main() (κυρίως πρόγραμμα), και των θέσεων που εμφανίζεται ο αριθμός Ν καλώντας την printArr.
*/
#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include <math.h>



void populate(int size,int a[]);
void printArr(int size,int a[]);
int checkTable(int size,int a[],int N,int T[]);

int main()
{
 int size=50,a[size],N,plithos,T[plithos];
 /*Δημιουργία πίνακα*/
 populate(size,a);
 /*Εκτύπωση αρχικού πίνακα*/ 
 printArr(size,a);
 /*Εισαγωγή δεδομένων*/ 
 printf("Dwse arithmo apo to 1 ews to 9: ");
 N=GetInteger();
 plithos=checkTable(size,a,N,T);
 /*Εκτύπωση αποτελεσμάτων*/ 
 printf("O arithmos %d emfanisthke %d fores. \n",N,plithos);
 printf("Stis Theseis: \n");
 printArr(plithos,T);
 return 0;
}


void populate(int row,int A[])
{
 int i;
  for(i=0;i<row;i++)
  {
      A[i]=rand() % 10 ;
  }
}

void printArr(int row,int A[])
{
 int i;
    for(i=0;i<row;i++)
    {
        printf("%7d",A[i]);
    }
 printf("\n");
}

int checkTable(int row,int A[],int N,int K[])
{
 int i,r=0;
    for(i=0;i<row;i++)
    {
        if(A[i]==N)
        {
          r+=1;
          K[r]=i;
       }
   }
 return r;
}
