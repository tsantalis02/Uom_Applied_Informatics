/*
File:a2jf4.c
   
Άδεια χρήσης: GNU General Public License v3.0
    
    Για τις παρακάτω λειτουργίες που αφορούν σε απλή συνδετική λίστα (Α.Σ.Λ.) με δείκτες να γραφούν διαφορετικά
    προγράμματα για καθεμιά από αυτές. Γνωρίζουμε τα εξής:
    • Κάθε κόμβος της ΑΣΛ ή των ΑΣΛ περιέχει έναν ακέραιο αριθμό.
    • Η είσοδος των δεδομένων θα γίνεται ως εξής: Πρώτα θα διαβάζεται για κάθε ΑΣΛ το πλήθος των κόμβων της Α.Σ.Λ.
    και στη συνέχεια τα στοιχεία της.
    • Σε όλες τις παρακάτω ασκήσεις η εισαγωγή στοιχείου, για την κατασκευή της υπάρχουσας λίστας γίνεται στην
    αρχή της λίστας.
    • Σε κάθε πρόγραμμα θα εμφανίζονται οι κόμβοι της αρχικής ή των αρχικών λιστών και στη συνέχεια αυτών που
    δημιουργούνται κατά την εκτέλεση του προγράμματος.
    • Η εμφάνιση των δεδομένων θα γίνεται ως εξής: Τα στοιχεία των κόμβων της Α.Σ.Λ. θα εμφανίζονται σε μια γραμμή
    με ένα κενό χαρακτήρα μεταξύ τους.
    • Αν κατά τη διάσχιση της λίστας διαπιστώσετε ότι η Α.Σ.Λ. είναι κενή, τότε να εμφανίζετε το μήνυμα ‘EMPTY LIST’.
    Σ’ όλα τα προγράμματα θα πρέπει να κατασκευάσετε την ΑΣΛ ή τις ΑΣΛς διαβάζοντας τα δεδομένα ως εξής: πλήθος
    στοιχείων λίστας, στοιχεία λίστας ή αν πρόκειται για 2 λίστες τότε θα τα διαβάζετε ως εξής: πλήθος στοιχείων λίστας1,
    στοιχεία λίστας1, πλήθος στοιχείων λίστας2, στοιχεία λίστας2
    Η καθεμία από τις παρακάτω λειτουργίες να υλοποιηθεί με τη χρήση συνάρτησης.
    
    (j) Να γραφεί συνάρτηση για την εισαγωγή m στοιχείων μετά το n-οστό στοιχείο της Α.Σ.Λ.
    Το πρωτότυπο της συνάρτησης είναι void insert_list_m_elements(ListPointer *List, int n);
    Το διάβασμα των δεδομένων θα γίνεται ως εξής: η Σ.Λ. (πλήθος στοιχείων λίστας, στοιχεία λίστας), στη συνέχεια ο
    αριθμός n, το πλήθος m και τέλος τα m στοιχεία. Το πλήθος m και τα m στοιχεία θα διαβάζονται μέσα στη
    insert_list_m_elements (). Ο έλεγχος της τιμής της n θα γίνεται μέσα στη συνάρτηση insert_list_m_elements () και
    αν n > πλήθος των κόμβων της Σ.Λ., τότε θα εμφανίζεται το μήνυμα ‘ERROR’.

*/

#include <stdio.h>
#include <stdlib.h>


typedef int ListElementType;    /* ο τύπος των στοιχείων της συνδεδεμένης λίστας
                                        ενδεικτικά τύπου int */
typedef struct ListNode *ListPointer;  //ο τύπος των δεικτών για τους κόμβους
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void insert_list_m_elements(ListPointer *List,int n);

int main(){
 ListPointer AList;
 ListElementType Item;
 int i,n,k;
  CreateList(&AList);
  // Εισαγωγή στοιχείων στις λίστες	
  printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS: ");
  scanf("%d",&k);
  for(i=0;i<k;i++){
    printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS: ");
    scanf("%d",&Item);
    LinkedInsert(&AList,Item,NULL);
  }
  // Εμφάνιση στοιχείων των λιστών	
  printf("************Arxiki lista************\n");
  LinkedTraverse(AList);
  printf("\nDWSE TI THESI,META APO TIN OPOIA THA EISAXTHOUN TA STOIXEIA: ");
  scanf("%d",&n);
  insert_list_m_elements(&AList,n);
  printf("************Teliki lista************\n");
  LinkedTraverse(AList);
return 0;
}

void CreateList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
  Επιστρέφει:  Τον μηδενικό δείκτη List
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* Δέχεται:   Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
  Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
  Επιστρέφει: True αν η λίστα είναι κενή και false διαφορετικά
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο,
                ένα στοιχείο δεδομένων Item και έναν δείκτη PredPtr.
   Λειτουργία: Εισάγει έναν κόμβο, που περιέχει το Item, στην συνδεδεμένη λίστα
                μετά από τον κόμβο που δεικτοδοτείται από τον PredPtr
                ή στην αρχή  της συνδεδεμένης λίστας,
                αν ο PredPtr είναι μηδενικός(NULL).
  Επιστρέφει:  Την τροποποιημένη συνδεδεμένη λίστα με τον πρώτο κόμβο της
                να δεικτοδοτείται από τον List.
*/
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
 /*  printf("Insert &List %p, List %p,  &(*List) %p, (*List) %p, TempPtr %p\n",
   &List, List,  &(*List), (*List), TempPtr); */
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}



void LinkedTraverse(ListPointer List)
/* Δέχεται:    Μια συνδεδεμένη λίστα με τον List να δείχνει στον πρώτο κόμβο.
   Λειτουργία: Διασχίζει τη συνδεδεμένη λίστα και
                επεξεργάζεται κάθε δεδομένο ακριβώς μια φορά.
   Επιστρέφει: Εξαρτάται από το είδος της επεξεργασίας.
*/
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
       CurrPtr=List;
       while(CurrPtr!=NULL){
   	    printf("%d ",CurrPtr->Data);
   	    CurrPtr=CurrPtr->Next;
       }
   	  /*  printf("%-16s\t%-4s\t%-16s\n", "CurrPtr","Data","Next");
        while ( CurrPtr!=NULL )
        {
             printf("%p\t%d\t%p\n",CurrPtr,(*CurrPtr).Data, (*CurrPtr).Next);
             CurrPtr = CurrPtr->Next;
        }
        */
   }
}

void insert_list_m_elements(ListPointer *List,int n)
{
    ListElementType Item;
    ListPointer TempPtr;
    int i,j,m;
     if(EmptyList(*List)){
        printf("EMPTY LIST\n");
     }else{
        TempPtr=*List;
        i=0;
        while(TempPtr->Next!=NULL && i!=n-1){
            TempPtr=TempPtr->Next;
            i++;
        }
        if(i<n-1 || n<1){
            printf("ERROR\n");
        }else{
           printf("DWSE TO PLITHOS TWN STOIXEIWN POU THA EISAXTHOUN: ");
           scanf("%d",&m);
           for(j=0;j<m;j++){
             printf("DWSE TON ARI8MO GIA EISAGWGH STH LISTA: ");
             scanf("%d",&Item);
             LinkedInsert(&(*List),Item,TempPtr);
             TempPtr=TempPtr->Next;
           }
        }
     }
}
