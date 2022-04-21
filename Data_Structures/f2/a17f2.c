/*
File:a17f2.c

Άδεια χρήσης: GNU General Public License v3.0
    
    Να υλοποιηθεί η συνάρτηση CopyStack η οποία θα δημιουργεί και θα επιστρέφει ένα αντίγραφο της δοσμένης
    στοίβας s1 αφήνοντας την αρχική στοίβα s1 αναλλοίωτη. Το πρωτότυπο της συνάρτησης είναι
                    StackType CopyStack(StackType *s1)
    Στο κυρίως πρόγραμμα δημιουργήστε τη στοίβα s1 εισάγοντας σ’ αυτή 20 αριθμούς. Για λόγους απλότητας
    μπορεί να χρησιμοποιηθεί ένας βρόχος for, σε κάθε επανάληψη του οποίου θα εισάγετε στη στοίβα την τιμής της
    μεταβλητής ελέγχου της for. Στη συνέχεια εμφανίστε το περιεχόμενο της στοίβας s1 (καλέστε τη βοηθητική
    συνάρτηση TraverseStack, η εμφάνιση των στοιχείων από τη θέση 0 .. Stack.top). Καλέστε την CopyStack και στη
    συνέχεια εμφανίστε τα στοιχεία της στοίβας s1 και τα στοιχεία της στοίβας s2. Δίνεται ένα στιγμιότυπο εκτέλεσης.
*/

#include <stdio.h>
#include<stdlib.h>

#define StackLimit 20 //  το όριο μεγέθους της στοίβας

typedef int StackElementType; // ο τύπος των στοιχείων  της στοίβας ενδεικτικά τύπος int

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);
StackType CopyStack(StackType *Stack);

int main(){
 StackType s1,s2;
 StackElementType i,temp;
  CreateStack(&s1); // Δημιουργία στοίβας s1 
  CreateStack(&s2); // Δημιουργία στοίβας s2
   for(i=0;i<20;i++){ // Γέμισμα στοίβας
    Push(&s1,i);
   }
  printf("Stack s1 ");  // Εκτύπωση στοίβας s1
  TraverseStack(s1);    // Εκτύπωση στοίβας s1
  printf("After copying s1 to s2 \n");
  printf("Stack s1 ");
  TraverseStack(s1); // Εκτύπωση στοίβας s1
  s2=CopyStack(&s1);  // Αντιγραφή στοίβας s1 στην s2
  printf("Stack s2 ");
  TraverseStack(s2); // Εκτύπωση στοίβας s2
return 0;
}

void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
    // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else{
        printf("Empty Stack...");
    }
}

/*
// ΑΥΤΗ Η ΕΚΔΟΣΗ ΕΜΦΑΝΙΖΕΙ ΤΑ ΣTOIXEIA ΤΗΣ ΣΤΟΙΒΑΣ ΑΠΟ ΤΗ ΘΕΣΗ TOP-0
void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
*/

 // ΑΥΤΗ Η ΕΚΔΟΣΗ ΕΙΝΑΙ ΣΤΙΣ ΣΗΜΕΙΩΣΕΙΣ ΚΑΙ ΕΜΦΑΝΙΖΕΙ ΤΑ ΣΤΟΙΧΕΙΑ ΤΗΣ ΣΤΟΙΒΑΣ ΑΠΟ ΤΗ ΘΕΣΗ 0-TOP
void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

StackType CopyStack(StackType *Stack)
{
 StackElementType x,i;
  for(i=0;i<20;i++){
   Pop(&(*Stack),&x); // Απώθηση στοιχείου και αποθήκευση στην μεταβήτή x
   Push(&(*Stack),x); // Ώθηση στοιχείου x στην στοίβα Stack (pointer της στοίβας Stack)
  }
}
