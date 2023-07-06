/*
File name:a13f5.c

*----------------------------

 Να γραφεί πρόγραμμα το οποίο:
    (α) Θα ζητά από τον χρήστη δύο θετικούς ακέραιους αριθμούς R (γραμμές) και C (στήλες) από το 1 μέχρι
    και το 10. Μπορείτε να υποθέσετε με ασφάλεια ότι ο χρήστης θα εισάγει σωστούς αριθμού σύμφωνα με τα
    προηγούμενα όρια. Δεν απαιτείται έλεγχος. Η εισαγωγή θα γίνεται από την συνάρτηση main.
    (β) Θα "γεμίζει" τα στοιχεία R x C ενός διδιάστατου πίνακα Α ακεραίων (διάστασης 10x10) με τυχαίους
    ακέραιους από 0 έως και 99 (rand() % 100), μέσω κλήσης μιας συνάρτησης populate_data.
    Δηλαδή το πρόγραμμα θα χρησιμοποιεί μέρος του πίνακα Α, βάσει των αριθμών R και C, που εισήγαγε ο χρήστης.
    (γ) Θα καλεί μια συνάρτηση print_array που θα τυπώνει τα R x C στοιχεία του πίνακα Α.
    (δ) Θα καλεί μια διαδικασία change_array, η οποία για κάθε γραμμή του πίνακα Α θα θέτει όσα
    στοιχεία είναι αριστερά του μέγιστου της γραμμής ίσα με αυτό (δηλαδή όσα είναι στην ίδια γραμμή με αυτό,
    αλλά έχουν μικρότερο δείκτη στήλης θα γίνουν ίσα με το μέγιστο).
    (ε) Τέλος, θα εμφανίζονται και πάλι τα στοιχεία του "αλλαγμένου" πίνακα κατά γραμμές.
    Όλες οι συναρτήσεις σας θα ακολουθούν το πρότυπο C99 για πίνακες 2 διαστάσεων. ΠΡΟΣΟΧΗ στις δηλώσεις των παραμέτρων των συναρτήσεων.
    Είναι άλλο η διάσταση του πίνακα, και άλλο ποιο μέρος του πίνακα έχει χρησιμοποιηθεί. θα πρέπει να περάσετε περισσότερες παραμέτρους.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "genlib.h"



void populate_data(int U,int V,int row,int col,int A[row][col]);
void print_array(int U,int V,int row,int col,int A[row][col]);
int change_array(int U,int V,int row,int col,int A[row][col]);


int main()
{
int R,C,K=10,L=10,A[10][10];
//Εισαγωγή δεδομένων(Read Data)
printf("Dwse ton arithmo twn grammwn:");
R=GetInteger();
printf("Dwse ton arithmo twn sthlwn:");
C=GetInteger();
//Δημιουργία πίνακα(Create the table A )
populate_data(R,C,K,L,A);
//Εκτύπωση αρχικού πίνακα(Printing initial table)
printf("ARXIKOS PINAKAS \n");
print_array(R,C,K,L,A);
change_array(R,C,K,L,A);
//Εκτύπωση αλλαγμένου πίνακα(Printing changed table)
printf("ALLAGMENOS PINAKAS \n");
print_array(R,C,K,L,A);
return 0;
}

void populate_data(int U,int V,int row,int col,int A[row][col])
{
 int i,j;
 for(i=0;i<U;i++)
 {
     for(j=0;j<V;j++)
     {
         A[i][j]=rand() % 100;
     }
 }
}

void print_array(int U,int V,int row,int col,int A[][col])
{
int i,j;
for(i=0;i<U;i++)
{
    for(j=0;j<V;j++)
    {
        printf("%7d",A[i][j]);
    }
printf("\n");
}
}

int change_array(int U,int V,int row ,int col,int A[][col])
{
int megisto,i,j,thesi;
for(i=0;i<U;i++)
{
    megisto=-1;
    for(j=0;j<V;j++)
    {
        if(A[i][j]>megisto)
        {
            megisto=A[i][j];
            thesi=j;
        }
    }
    if(thesi!=0)
    {
        for(j=0;j<thesi;j++)
        {
            A[i][j]=megisto;
        }
    }
}
}
