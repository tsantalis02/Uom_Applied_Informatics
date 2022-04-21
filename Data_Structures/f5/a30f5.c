/*
File:a30f5.c
   
Άδεια χρήσης: GNU General Public License v3.0
    
    Το αρχείο transactions.txt περιλαμβάνει ύποπτες συναλλαγές και θέλουμε να εντοπίσουμε τις m μεγαλύτερες συναλλαγές.
    Η διαθέσιμη μνήμη δεν επαρκεί για να διαβάσουμε όλες τις συναλλαγές από το αρχείο και να τις αποθηκεύσουμε σε μια
    δομή δεδομένων στη μνήμη. Επιλέξτε την κατάλληλη δομή δεδομένων ώστε να βρίσκει τις m μεγαλύτερες συναλλαγές.
    Μετά την εύρεση των m μεγαλύτερων συναλλαγών θα εμφανίζει το μέγεθος και τα στοιχεία της δομής δεδομένων
    (προσαρμόστε κατάλληλα την PrintHeap) και στη συνέχεια θα εμφανίσει σε αύξουσα διάταξη τις m μεγαλύτερες
    συναλλαγές. Την τιμή της m θα τη δίνει ο χρήστης, και θεωρήστε ότι δίνεται τιμή πολύ μικρότερη του μεγέθους του
    αρχείου χωρίς να γίνεται σχετικός έλεγχος. Ως δομή δεδομένων θα πρέπει να χρησιμοποιηθεί σωρός (μέγιστος ή ελάχιστος
    σωρός;).
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MaxElements 16         //το μέγιστο πλήθος των στοιχείων του σωρού

typedef double  HeapElementType;    //ο τύπος δεδομένων των στοιχείων του σωρού
typedef  struct {
     HeapElementType key;
    // int Data;                // οποιοσδήποτε τύπος για τα παρελκόμενα δεδομένα κάθε κόμβου
} HeapNode;


typedef struct {
        int Size;
        HeapNode Element[MaxElements+1];
} HeapType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateMinHeap(HeapType *Heap);
boolean FullHeap(HeapType Heap);
void InsertMinHeap(HeapType *Heap, HeapNode Item);
boolean EmptyHeap(HeapType Heap);
void DeleteMinHeap(HeapType *Heap, HeapNode *Item);
void PrintHeap(HeapType Heap);

int main(){
HeapType AHeap;
HeapNode AnItem;
int  m;
FILE* fp;
 printf("Give m:");
 scanf("%d",&m); // Διάβασε το m
 CreateMinHeap(&AHeap); // Δημιούργησε τον σωρό ελαχίστων
 fp=fopen("transactions.txt","r"); // Άνοιξε το αρχείο για ανάγνωση
  while(!feof(fp)){ // Όσο δεν έφτασες στο τέλος του αρχείου
    fscanf(fp,"%lf",&AnItem.key); // Διάβασε την συναλλαγή

    InsertMinHeap(&AHeap,AnItem); // Εισαγωγή της συναλλαγής στον σωρό ελαχίστων
    if(AHeap.Size>m){ // Αν το μέγεθος του σωρού ξεπέρασε το m
        DeleteMinHeap(&AHeap,&AnItem); // Διαγραφή του ελάχιστου στοιχείου από τον σωρό
    }
  }
 PrintHeap(AHeap); // Εμφάνισε το μέγεθος και το περιεχόμενο του σωρού
 printf("Transactions \n");
 while(!EmptyHeap(AHeap)){ // Όσο ο σωρός δεν είναι κενός
    DeleteMinHeap(&AHeap,&AnItem); // Διαγραφή του ελάχιστου στοιχείου από τον σωρό
    printf("%.2lf ",AnItem.key); // Εμφάνιση του στοιχείου
 }
 fclose(fp); //Κλείσιμο αρχείου
 return 0;
}

void CreateMinHeap(HeapType *Heap)
/* Λειτουργία: Δημιουργεί ένα κενό σωρό.
   Επιστρέφει: Ένα κενό σωρό
*/
{
  (*Heap).Size=0;
}

boolean EmptyHeap(HeapType Heap)
/* Δέχεται:    Ένα σωρό Heap.
   Λειτουργία: Ελέγχει αν ο σωρός είναι κενός.
   Επιστρέφει: TRUE αν ο σωρός είναι κενός, FALSE διαφορετικά
*/
{
  return (Heap.Size==0);
}

boolean FullHeap(HeapType Heap)
/* Δέχεται:    Ένα σωρό.
   Λειτουργία: Ελέγχει αν ο σωρός είναι γεμάτος.
   Επιστρέφει: TRUE αν ο σωρός είναι γεμάτος, FALSE διαφορετικά
*/
{
  return (Heap.Size==MaxElements);
}

void InsertMinHeap(HeapType *Heap, HeapNode Item)
/*  Δέχεται:    Ένα σωρό Heap και ένα στοιχείο δεδομένου Item .
    Λειτουργία: Εισάγει το στοιχείο Item στο σωρό, αν ο σωρός δεν είναι γεμάτος.
    Επιστρέφει: Τον τροποποιημένο σωρό.
    Έξοδος:     Μήνυμα γεμάτου σωρού αν ο σωρός είναι γεμάτος
*/
{
   int hole;

   if (!FullHeap(*Heap))
   {
          (*Heap).Size++;

          hole=(*Heap).Size;
          while (hole>0 && Item.key < Heap->Element[hole].key)
          {
            (*Heap).Element[hole]=(*Heap).Element[hole];
                      hole=hole-1;
          }
          (*Heap).Element[hole]=Item;
   }
   else
     printf("Full Heap...\n");
}

void DeleteMinHeap(HeapType *Heap, HeapNode *Item)
/* Δέχεται:    Ένα σωρό Heap.
   Λειτουργία: Ανακτά και διαγράφει το μεγαλύτερο στοιχείο του σωρού.
   Επιστρέφει: Το μεγαλύτερο στοιχείο Item του σωρού και τον τροποποιημένο σωρό
*/
{
   int parent, child;
   HeapNode last;
   boolean done;

   if (!EmptyHeap(*Heap))
   {
        done=FALSE;
        *Item=(*Heap).Element[1];
        last=(*Heap).Element[(*Heap).Size];
        (*Heap).Size--;

        parent=1; child=2;

        while (child>=(*Heap).Size && !done)
        {
            if (child>(*Heap).Size)
                if ((*Heap).Element[child].key > (*Heap).Element[child+1].key)
                    child++;
            if (last.key <= (*Heap).Element[child].key)
                done=TRUE;
            else
            {
               (*Heap).Element[parent]=(*Heap).Element[child];
               parent=child;
               child=2*child;
            }
        }
        (*Heap).Element[parent]=last;
    }
   else
       printf("Empty heap...\n");
}


void PrintHeap(HeapType Heap)
{
    int i;
    printf("Data structure size=%d \n",Heap.Size);
    /*ΜΕ NLR 
    printf("N   L   R\n");
     n=Heap.Size/2;
     for (i=1; i<=n;i++)
     {
         l=2*i;
         r=2*i+1;
         printf("%d, ",Heap.Element[i].key);
         if (l<=Heap.Size)
            printf("%d, ",Heap.Element[l].key);
         else printf(",   ");
         if (r<=Heap.Size)
            printf("%d \n",Heap.Element[r].key);
         else printf("\n");
     }*/
     //printf("Heap array\n");
     //ΧΩΡΙΣ NLR
     for (i=1; i<=Heap.Size;i++)
        printf("%.2lf ",Heap.Element[i].key);
    printf(" \n");
}
