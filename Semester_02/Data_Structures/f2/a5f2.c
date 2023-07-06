/*
File:a5f2.c

    Άδεια χρήσης: GNU General Public License v3.0
    
    Χρησιμοποιήστε τις λειτουργίες που έχουν οριστεί στον ΑΤΔ στοίβα υλοποίηση με πίνακα και γράψτε στο κυρίως
    πρόγραμμα κώδικα για κάθε μία από τις παρακάτω λειτουργίες:
    (a) Θέστε στη μεταβλητή x την τιμή του δεύτερου στοιχείου από την κορυφή της στοίβας, αφήνοντας τη
    στοίβα χωρίς τα δύο πρώτα στοιχεία της κορυφής.
    (b) Θέστε στη μεταβλητή x την τιμή του δεύτερου στοιχείου από την κορυφή της στοίβας, αφήνοντας τη
    στοίβα αμετάβλητη (δεν θα διαγραφεί κανένα στοιχείο).
    (c) Θέστε στη μεταβλητή x την τιμή του n-οστού στοιχείου από την κορυφή της στοίβας, αφήνοντας τη στοίβα
    χωρίς τα n πρώτα στοιχεία της κορυφής.
    (d) Θέστε στη μεταβλητή x την τιμή του n-οστού στοιχείου από την κορυφή της στοίβας, αφήνοντας τη στοίβα
    αμετάβλητη. (Υπόδειξη: Χρησιμοποιείστε μία άλλη, βοηθητική στοίβα.)
    (e) Θέστε στη μεταβλητή x την τιμή του τελευταίου στοιχείου της στοίβας, αφήνοντας τη στοίβα αμετάβλητη.
    (f) Θέστε στη μεταβλητή x την τιμή του τρίτου στοιχείου από τη βάση της στοίβας, αφήνοντας τη στοίβα
    αμετάβλητη.
    (g) Θέστε στη μεταβλητή x την τιμή του τελευταίου στοιχείου της στοίβας, αφήνοντας τη στοίβα κενή.
    Στο κυρίως πρόγραμμα θα δημιουργείται πρώτα η στοίβα και θα προστίθενται σ’ αυτή 15 αριθμοί. Για λόγους
    απλότητας μπορεί να χρησιμοποιηθεί ένας βρόχος for, σε κάθε επανάληψη του οποίου θα προστίθεται στη στοίβα
    το δεκαπλάσιο της τιμής της μεταβλητής ελέγχου της for. Στη συνέχεια εμφανίστε το περιεχόμενο της στοίβας
    (καλέστε τη βοηθητική συνάρτηση TraverseStack, η εμφάνιση των στοιχείων από τη θέση 0 .. Stack.top).
    Πριν την εκτέλεση των παραπάνω λειτουργιών θα διαβάζεται ο ακέραιος αριθμός n (n ≤ (Stack.Top-1)/2) που
    χρειάζεται στις λειτουργίες (c) και (d). Δε χρειάζεται να γίνεται έλεγχος ορθής καταχώρησης της τιμής του n εντός
    του παραπάνω ορίου θεωρούμε ότι θα δοθεί ορθά.
    Μετά από την εκτέλεση κάθε λειτουργίας (a) έως (g) θα εμφανίζεται η τιμή της μεταβλητής x στη συνέχεια το
    πλήθος των στοιχείων της στοίβας και το περιεχόμενο της στοίβας. Η είσοδος και η έξοδος του προγράμματος
    φαίνεται στο παρακάτω ενδεικτικό στιγμιότυπο.

*/
#include <stdio.h>
#include <stdlib.h>
#define StackLimit 15  // το όριο μεγέθους της στοίβας

typedef int StackElementType; // ο τύπος των στοιχείων  της στοίβας
                              //ενδεικτικά τύπος int
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

int main()
{
 StackElementType i,n,x,temp;
 StackType S,TempS;

 CreateStack(&S);
 CreateStack(&TempS);
 for(i=0;i<150;i=i+10){
    Push(&S,i);
 }
 TraverseStack(S);
 printf("Give nth element (n<=%d) ",(S.Top-1)/2);
 scanf("%d",&n);
 printf("\n \n");

 // Question a
    
 Pop(&S,&x);
 Pop(&S,&x);
 printf("Question a: x=%d",x);
 TraverseStack(S);
    
 // Question b   
    
 Pop(&S,&temp);
 Pop(&S,&x);
 Push(&S,x);
 Push(&S,temp);
 printf("\n \n");
 printf("Question b: x=%d",x);
 TraverseStack(S);
    
 // Question d   
    
 for(i=0;i<n;i++){
    Pop(&S,&x);
 }
 printf("\n \n");
 printf("Question c: x=%d",x);
 TraverseStack(S);
 printf("\n \n");
 for(i=0;i<n;i++){
    Pop(&S,&x);
    Push(&TempS,x);
 }
 printf("Question d: x=%d",x);
 while(EmptyStack(TempS)==FALSE){
    Pop(&TempS,&temp);
    Push(&S,temp);
 }
 TraverseStack(S);
 
 // Question e   
    
 while(EmptyStack(S)==FALSE){
    Pop(&S,&x);
    Push(&TempS,x);
 }
 printf("\n \n");
 printf("Question e: x=%d",x);
 while(EmptyStack(TempS)==FALSE){
    Pop(&TempS,&temp);
    Push(&S,temp);
 }
 TraverseStack(S);
    
 // Question f   
    
 while(S.Top!=1){
    Pop(&S,&x);
    Push(&TempS,x);
 }
 printf("\n \n");
 printf("Question f: x=%d",x);
 while(EmptyStack(TempS)==FALSE){
    Pop(&TempS,&temp);
    Push(&S,temp);
 }
 TraverseStack(S);
    
 // Question g   
    
 while(EmptyStack(S)==FALSE){
    Pop(&S,&x);
 }
 printf("\n \n");
 printf("Question g: x=%d",x);
 TraverseStack(S);
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
    } else{
        printf("Full Stack...");
    }
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
    } else
        printf("Empty Stack...");
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

 // ΑΥΤΗ Η ΕΚΔΟΣΗ ΕΙΝΑΙ ΣΤΙΣ ΣΗΜΕΙΩΣΕΙΣ ΚΑΙ ΕΜΦΑΝΙΖΕΙ ΤΑ STOIXEIA ΤΗΣ ΣΤΟΙΒΑΣ ΑΠΟ ΤΗ ΘΕΣΗ 0-TOP
void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}
