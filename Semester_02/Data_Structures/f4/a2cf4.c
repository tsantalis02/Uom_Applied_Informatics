/*
File:a2cf4.c
   
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
    
    (c) Συνένωση 2 Α.Σ.Λ. σε μία (πχ 1 ΑΣΛ: 4, 3, 2, 1 και 2 ΑΣΛ: 8, 7, 6, τελική ΑΣΛ: 6, 7, 8, 1, 2, 3, 4). Δίνεται το πρωτότυπο
    της συνάρτησης: 
    void concat_list(ListPointer List, ListPointer BList, ListPointer *FinalList)
    (τα στοιχεία των λιστών δεν ακολουθούν κάποια διάταξη)

*/
#include <stdio.h>
#include <stdlib.h>


typedef int ListElementType;/* ο τύπος των στοιχείων της συνδεδεμένης λίστας
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
void concat_list(ListPointer AList,ListPointer BList,ListPointer *FinalList);

int main(){
 ListPointer AList,BList,FinalList;
 ListElementType Item,i,K;
  CreateList(&AList);
  CreateList(&BList);
  CreateList(&FinalList);
  // Εισαγωγή στοιχείων στις λίστες	
  printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS 1: ");
  scanf("%d",&K);
  for(i=0;i<K;i++){
    printf("DWSE TOM ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS 1: ");
    scanf("%d",&Item);
    LinkedInsert(&AList,Item,NULL);
  }
  printf("DWSE TO PLH8OS TWN STOIXEIWN THS LISTAS 2: ");
  scanf("%d",&K);
  for(i=0;i<K;i++){
    printf("DWSE TON ARI8MO GIA EISAGWGH STHN ARXH THS LISTAS 2: ");
    scanf("%d",&Item);
    LinkedInsert(&BList,Item,NULL);
  }
  // Εμφάνιση στοιχείων των λιστών	
  printf("LISTA 1: \n");
  LinkedTraverse(AList);
  printf("\nLISTA 2: \n");
  LinkedTraverse(BList);
  // Κλήση συνάρτησης	
  concat_list(AList,BList,&FinalList);
  // Εμφάνιση τελικής λίστας	
  printf("\nSYNENWMENH LISTA: \n");
  LinkedTraverse(FinalList);
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


void concat_list(ListPointer AList,ListPointer BList,ListPointer *FinalList)
{
    ListPointer CurrPtr;
    
     //Διασχίζεται η 1η λίστα και τα στοιχεία της εισάγονται ένα-ένα στην τελική λίστα
	
    CurrPtr=AList;
    while(CurrPtr!=NULL){
        LinkedInsert(&(*FinalList),CurrPtr->Data,NULL);
        CurrPtr=CurrPtr->Next;
    }
	
    //Διασχίζεται η 1η λίστα και τα στοιχεία της εισάγονται ένα-ένα στην τελική λίστα	
    CurrPtr=BList;
    while(CurrPtr!=NULL){
      LinkedInsert(&(*FinalList),CurrPtr->Data,NULL);
      CurrPtr=CurrPtr->Next;
    }
}
