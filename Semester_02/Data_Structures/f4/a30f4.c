/*
File:a30f4.c

Άδεια χρήσης: GNU General Public License v3.0
    
    Σε μια ΣΛ θέλουμε να καταχωρούμε τον Αριθμό Μητρώο (int) και τον βαθμό (float) ενός μαθητή. Τροποποιήστε τον
    τύπο ListElementType ώστε να αποθηκεύει τον ΑΜ και το βαθμό του μαθητή. Κάντε τις κατάλληλες τροποποιήσεις όπου
    είναι απαραίτητο, στις συναρτήσεις που θα αντιγράψετε από τα αρχεία L_ListADT.c & L_ListADT.h. Θέλουμε να εντοπίζουμε
    και να εμφανίσουμε τα στοιχεία των μαθητών που έχουν τον ελάχιστο βαθμό. Να υλοποιήσετε τη συνάρτηση FindMins που
    θα δέχεται 2 παραμέτρους: τη ΣΛ με τα στοιχεία των μαθητών και μια στοίβα όπου θα καταχωρεί τους ΑΜ όλων των
    μαθητών με τον ίδιο ελάχιστο βαθμό, και θα επιστρέφει την τιμή του ελάχιστου βαθμού. To πρωτότυπο της συνάρτησης:
    float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack)
    Αφού εντοπιστούν οι μαθητές με τους ελάχιστους βαθμούς, στη συνέχεια θα εμφανιστούν στην οθόνη.
    Η εμφάνιση των AM των μαθητών με τον ίδιο ελάχιστο βαθμό θα γίνεται στη main() με χρήση των επιτρεπόμενων
    λειτουργιών της στοίβας (άδειασμα στοίβας). Στη συνέχεια θα καλείται η βοηθητική συνάρτηση TraverseStack για την
    επαλήθευση της ορθής υλοποίησης αυτού του ερωτήματος (η στοίβα θα πρέπει να είναι κενή μετά την «εμφάνιση»-
    διαγραφή από τη στοίβα των ΑΜ). Το περιεχόμενο κάθε κόμβου της ΣΛ θα εμφανίζεται ως εξής: <ΑΜ, Βαθμός> πχ αν ο
    κόμβος της ΣΛ είναι στη θέση 0 του πίνακα με ΑΜ 5 και βαθμό 10 και ο επόμενος κόμβος της ΣΛ είναι αποθηκευμένος στη
    θέση 2 του πίνακα, τότε η εμφάνιση του κόμβου θα είναι: (0|<5,10.0> -> 2) που σημαίνει ότι ο κόμβος με περιεχόμενο 5, 10
    είναι αποθηκευμένος στη θέση 0 του πίνακα και έχει επόμενο κόμβο αποθηκευμένο στη θέση 2 του πίνακα.
    Το πρόγραμμα θα πρέπει να εκτελεί κατά σειρά τις παρακάτω λειτουργίες και οι κλήσεις των συναρτήσεων θα γίνονται από τη main().
    A. Αρχικοποίηση storage pool
    B. Δημιουργία ΣΛ (μέγιστο μέγεθος 10)
    C. Εμφάνιση της storage pool
    D. Εμφάνιση των στοιχείων της ΣΛ
    E. Εισαγωγή 5 στοιχείων στην ΣΛ. (Η εισαγωγή στοιχείου θα γίνεται πάντα στην αρχή της ΣΛ)
    F. Εμφάνιση της storage pool
    G. Εμφάνιση των στοιχείων της ΣΛ
    H. Έλεγχος εάν η ΣΛ είναι άδεια. Αν η ΣΛ είναι άδεια εμφανίζει μήνυμα «Empty List» διαφορετικά «Not an Empty List»
    I. Έλεγχος εάν η ΣΛ είναι γεμάτη. Αν η ΣΛ είναι γεμάτη εμφανίζει μήνυμα «Full List» διαφορετικά «Not a Full List»
    J. Εμφάνιση του ελάχιστου βαθμού και των ΑΜ των μαθητών με το ελάχιστο βαθμό
    K. Κλήση της TraverseStack για την επαλήθευση της ορθής υλοποίησης του ερωτήματος J
    L. Εμφάνιση της storage pool
    M. Εμφάνιση των στοιχείων της ΣΛ

*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NumberOfNodes 10    /*όριο μεγέθους της συνδεδεμένης λίστας 10*/
#define StackLimit 11
#define NilValue -1      // ειδική μηδενική τιμή δείχνει το τέλος της Συνδ.λίστας

typedef struct{
    float bathmos;
    int am;
} ListElementType; /*τύπος δεδομένων για τα στοιχεία της συνδεδεμένης λίστας*/

typedef int ListPointer;
// Τύποι δεδομένων στοίβας
typedef int StackElementType;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

typedef struct{
 int Top;
 StackElementType Element[StackLimit];
}StackType;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
boolean FullList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void TraverseLinked(ListPointer List, NodeType Node[]);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
float FindMins(ListPointer List,NodeType Node[],StackType *Stack);
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
boolean FullStack(StackType Stack);
void TraverseStack(StackType Stack);

int main(){
 NodeType N[NumberOfNodes];
 ListPointer ptr,L,i,pred;
 ListElementType Item;
 StackElementType x;
 StackType S;
 float min;
  // Ερώτημα A
  InitializeStoragePool(N,&ptr);
  // Ερώτημα B
  CreateList(&L);
  // Ερώτημα C  
  printf("---------Question C-----------\n");
  printf("---------Storage pool---------\n");
  printAll(L,ptr,N);
  // Ερώτημα D  
  printf("---------Question D-----------\n");
  printf("---------Linked list----------\n");
  TraverseLinked(L,N);
  // Ερώτημα E  
  printf("---------Question E-----------\n");
  for(i=0;i<5;i++){
    printf("DWSE AM GIA EISAGWGH STH LISTA: ");
    scanf("%d",&Item.am);
    printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
    scanf("%f",&Item.bathmos);
    pred=NilValue;
    Insert(&L,N,&ptr,pred,Item);
  }
  // Ερώτημα F  
  printf("---------Question F-----------\n");
  printf("---------Storage pool---------\n");
  printAll(L,ptr,N);
  // Ερώτημα G  
  printf("---------Question G-----------\n");
  printf("---------Linked list----------\n");
  TraverseLinked(L,N);
  // Ερώτημα H  
  printf("---------Question H-----------\n");
    if(EmptyList(L)){
        printf("Empty List\n");
    }else{
        printf("Not an Empty List\n");
    }
  // Ερώτημα I  
  printf("---------Question I-----------\n");
       if(FullList(ptr)){
            printf("Full List\n");
       }else{
            printf("Not a Full List\n");
       }
  min=FindMins(L,N,&S);
  // Ερώτημα J  
  printf("---------Question J------------\n");
  printf("Min value=%.1f\n",min);
  printf("AM with min grade are: ");
  while(!EmptyStack(S)){
    Pop(&S,&x);
    printf(" %d",x);
    }
  printf("\n");
  // Ερώτημα K  
  printf("---------Question K------------\n");
  TraverseStack(S);
  // Ερώτημα L  
  printf("---------Question L------------\n");
  printf("---------Storage pool----------\n");
  printAll(L,ptr,N);
  // Ερώτημα M  
  printf("---------Question M------------\n");
  TraverseLinked(L,N);
return 0;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr που δείχνει στον
                πρώτο διαθέσιμο κόμβο.
  Λειτουργία: Αρχικοποιεί τον πίνακα Node ως συνδεδεμένη λίστα συνδέοντας μεταξύ
                τους διαδοχικές εγγραφές του πίνακα,
                και αρχικοποιεί τον δείκτη FreePtr .
  Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον
                δείκτη FreePtr του πρώτου διαθέσιμου κόμβου
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.am=-1;
        Node[i].Data.bathmos=-1.0;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data.am=-1;
    Node[NumberOfNodes-1].Data.bathmos=-1.0;
    *FreePtr=0;
}

void CreateList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
   Επιστρέφει: Έναν (μηδενικό) δείκτη που δείχνει σε κενή λίστα
*/
{
  *List=NilValue;
}

boolean EmptyList(ListPointer List)
/* Δέχεται:    Έναν δείκτη List που δείχνει σε μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
   Επιστρέφει: True αν η συνδεδεμένη λίστα είναι κενή και false διαφορετικά
*/
{
  return (List==NilValue);
}

boolean FullList(ListPointer FreePtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι γεμάτη.
   Επιστρέφει: True αν η συνδεδεμένηλίστα είναι γεμάτη, false διαφορετικά
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr.
  Λειτουργία: Αποκτά έναν "ελεύθερο" κόμβο που τον δείχνει ο δείκτης P.
  Επιστρέφει: Τον δείκτη P και τον τροποποιημένο  δείκτη FreePtr
                που δεικτοδοτεί στο πρώτο διαθέσιμο κόμβο
*/
{
  *P = *FreePtr;
  if (!FullList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}


void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* Δέχεται:    Μια συνδεδεμένη λίστα, τον πίνακα Node, τον δείκτη PredPtr και
                ένα στοιχείο Item.
  Λειτουργία: Εισάγει στη συνδεδεμένη λίστα, αν δεν είναι γεμάτη, το στοιχείο
                Item μετά από τον κόμβο στον οποίο δείχνει ο δείκτης PredPtr.
  Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα, τον τροποποιημένο πίνακα Node
                και τον δείκτη FreePtr.
  Εξοδος:     Μήνυμα γεμάτης λίστας, αν η συνδεδεμένη λίστα είναι γεμάτη
*/
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data.am =Item.am;
        Node[TempPtr].Data.bathmos=Item.bathmos;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data.am =Item.am;
        Node[TempPtr].Data.bathmos=Item.bathmos;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}


void TraverseLinked(ListPointer List, NodeType Node[])
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Κάνει διάσχιση της συνδεδεμένης λίστας, αν δεν είναι κενή.
   Έξοδος:     Εξαρτάται από την επεξεργασία
*/
{
  ListPointer CurrPtr;

  if (!EmptyList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d:<%d,%.1f> ->%d) ",CurrPtr,Node[CurrPtr].Data.am,Node[CurrPtr].Data.bathmos ,Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d:<%d,%.1f> ->%d) ",i,Node[i].Data.am,Node[i].Data.bathmos , Node[i].Next);
    printf("\n");
}

float FindMins(ListPointer List,NodeType Node[],StackType *Stack){
int CurrPtr;
int  min;
StackElementType Item;

CreateStack(&(*Stack));
if(!EmptyList(List)){
    CurrPtr=List;
    min=Node[CurrPtr].Data.bathmos;
    while(CurrPtr!=NilValue){
        if(Node[CurrPtr].Data.bathmos<=min){
            if(Node[CurrPtr].Data.bathmos<min){
                   while(EmptyStack(*Stack)){
                    Pop(&(*Stack),&Item);
                   }
                   Node[CurrPtr].Data.bathmos=min;
            }
            Push(&(*Stack),Node[CurrPtr].Data.am);
        }
        CurrPtr--;
    }
}else{
   printf("Empty List...\n");
  }
return  min;
}

void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
  Stack -> Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
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

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
     return (Stack.Top == (StackLimit - 1));
}

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
