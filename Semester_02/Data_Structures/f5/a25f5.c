/*
File:a25f5.c
   
Άδεια χρήσης: GNU General Public License v3.0
    
    Υλοποιείστε την αναδρομική συνάρτηση int CountLeaves(BinTreePointer Root) η οποία θα υπολογίζει το πλήθος των
    φύλλων ενός ΔΔΑ το οποίο και θα επιστρέφει. Στο ΔΔΑ θα καταχωρούνται ακέραιοι. Θα εμφανίζονται οι κόμβοι του ΔΔΑ
    σε αύξουσα διάταξη και στη συνέχεια θα εμφανίζεται το πλήθος των φύλλων του ΔΔΑ στο κυρίως πρόγραμμα.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef int BinTreeElementType;             /*ο τύπος των στοιχείων του ΔΔΑ
                                                ενδεικτικά τύπου int */
typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTInorder(BinTreePointer Root);
int CountLeaves(BinTreePointer Root);

int main(){
  BinTreePointer ARoot;
  BinTreeElementType n;
  char ch;

  CreateBST(&ARoot); // Δημιουργία ΔΔΑ
  do{ // Επαναληπτικά
    printf("Enter a number for insertion in  the Tree:");
    scanf("%d",&n); // Διάβασε τον αριθμό
    RecBSTInsert(&ARoot,n); // Εισαγωγή του αριθμού στο ΔΔΑ
    printf("Continue Y/N:"); // Ερώτηση για εισαγωγή και άλλων αριθμών
    do{ // Επαναληπτικά
        scanf("%c", &ch); // Διάβασε τον χαρακτήρα ch
      } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y'); // όσο ο χαρακτήρας δεν είναι N ή Υ
  }while (toupper(ch)!='N'); // όσο ο χαρακτήρας δεν είναι Ν
  printf("Elements of BST\n");
  RecBSTInorder(ARoot); // Εμφάνιση των στοιχείων του ΔΔΑ (σε αύξουσα διάταξη)
  printf("\nNumber of leaves %d",CountLeaves(ARoot)); // Εμφάνιση του πλήθους των φύλλων
  return 0;
  }

 void CreateBST(BinTreePointer *Root)
 /* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
 */
 {
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (Item < (*Root) ->Data)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (Item > (*Root) ->Data)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}


 void RecBSTInorder(BinTreePointer Root)
 /* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
 {
    if (Root!=NULL) { 
        RecBSTInorder(Root->LChild);
        printf("%d ",Root->Data);
        RecBSTInorder(Root->RChild);
    }
}

int CountLeaves(BinTreePointer Root){
  if(BSTEmpty(Root)){ // Αν το ΔΔΑ είναι κενό
    return 0; // Επέστρεψε 0
  }else if(Root->LChild==NULL && Root->RChild==NULL){ // Αν ο κόμβος είναι φύλλο
    return 1; // Επέστρεψε 1
    }else{
     // Επέστρεψε το άθροισμα της Countleaves για το αριστερό και το δεξί υποδέντρο 
     return(CountLeaves(Root->LChild)+CountLeaves(Root->RChild));
    }
}
