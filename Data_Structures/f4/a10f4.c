/*
File:a10f4.c
    
    Άδεια χρήσης: GNU General Public License v3.0
    
    Να γίνει πρόγραμμα που θα προσομοιώνει μια ουρά με τη βοήθεια δύο στοιβών, δηλαδή οι λειτουργίες της ουράς θα
    προσομοιώνονται με τις λειτουργίες της στοίβας. Αντί να χρησιμοποιήσετε μια ουρά αρκεί να χρησιμοποιήσετε 2 στοίβες.
    Κάθε κόμβος περιέχει έναν ακέραιο αριθμό και η εισαγωγή δεδομένων θα γίνεται ως εξής: πλήθος στοιχείων, στοιχεία. Το 
    πρόγραμμα θα εμφανίζει τα περιεχόμενα και των 2 στοιβών. Η 2η στοίβα έχει καταχωρημένα τα στοιχεία όπως θα ήταν αν
    είχαμε χρησιμοποιήσει μια ουρά.

*/
#include <stdio.h>
#include <stdlib.h>

typedef int StackElementType;

typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);

int main(){
 StackPointer S1,S2;
 StackElementType Item;
 int k,i;

 CreateStack(&S1); //Δημιουργώ τη στοίβα S1
 CreateStack(&S2); //Δημιουργώ τη στοίβα S2
 printf("PLITHOS STOIXEIWN:");
 scanf("%d",&k); //Διαβάζω το πλήθος των στοιχείων που θα εισαχθούν στη στοίβα
 for(i=0;i<k;i++){
    printf("DWSE TO %do STOIXEIO:",i+1);
    scanf("%d",&Item); // Διαβάζω 1-1 στοιχείο και το εισάγω στην στοίβα S1
    Push(&S1,Item);
 }
 printf("*********1i stoiva*********\n");
 TraverseStack(S1);  //Εμφανίζω τα στοιχεία της στοίβας S1
 for(i=0;i<k;i++){
    Pop(&S1,&Item);  //Απωθώ το κορυφαίο στοιχείο Item από τη στοίβα S1
    Push(&S2,Item);  //Εισάγω στο στοιχείο Item στη στοίβα S2
 }
 printf("*********2i stoiva*********\n");
 TraverseStack(S2);  //Εμφανίζω τα στοιχεία της στοίβας S2
 return 0;
}

void CreateStack(StackPointer *Stack)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη στοίβα. 
   Επιστρέφει: Μια κενή συνδεδεμένη στοίβα, Stack  
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* Δέχεται:     Μια συνδεδεμένη στοίβα, Stack.
   Λειτουργία:  Ελέγχει αν η Stack είναι κενή.
   Επιστρέφει:  TRUE αν η στοίβα είναι κενή, FALSE διαφορετικά
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον 
                δείκτη Stack και ένα στοιχείο Item. 
   Λειτουργία: Εισάγει στην κορυφή της συνδεδεμένης στοίβας, το στοιχείο Item. 
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα 
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη στοίβα που η κορυφή της δεικτοδοτείται από τον δείκτη Stack. 
   Λειτουργία: Αφαιρεί από την κορυφή της συνδεδεμένης στοίβας, 
                αν η στοίβα δεν είναι κενή, το στοιχείο Item. 
   Επιστρέφει: Την τροποποιημένη συνδεδεμένη στοίβα και το στοιχείο Item. 
   Έξοδος:     Μήνυμα κενής στοίβας, αν η συνδεδεμένη στοίβα είναι κενή 
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}

void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}

