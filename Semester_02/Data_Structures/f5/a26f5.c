/*
File:a26f5.c
   
Άδεια χρήσης: GNU General Public License v3.0
    
    Δίνεται το αρχείο φοιτητών “foitites.dat”. Κάθε στοιχείο του αρχείου αυτού είναι μια εγγραφή με πεδία:
    Αριθμός μητρώου (ΑΜ: int), Επώνυμο (αλφαριθμητικό 20 χαρακτήρες), Ονομα (αλφαριθμητικό 20 χαρακτήρες), Φύλο
    (χαρακτήρας, τιμή F/M), Ετος (int), Βαθμός (μέσος όρος: float). Για την πιο αποτελεσματική επεξεργασία του αρχείου
    αυτού δημιουργείται ένα ευρετήριο (index) ως ΔΔΑ. Κάθε στοιχείο του ευρετηρίου αυτού αποτελείται από τον ΑΜ και τον
    αντίστοιχο αριθμό εγγραφής (γραμμής) στο αρχείο “foitites.dat”. Η αρίθμηση των γραμμών του αρχείου ξεκινούν από την
    τιμή 0.
    Γράψτε ένα πρόγραμμα που εκτελεί τις παρακάτω λειτουργίες και χρησιμοποιεί ως ευρετήριο ένα ΔΔΑ:
    1. Δημιουργία του index (ΔΔΑ) από το αρχείο “foitites.dat”.
    Θα διαβάζει 1-1 τις εγγραφές του αρχείου “foitites.dat”και θα καταχωρεί στο ΔΔΑ τον ΑΜ του φοιτητή και τον
    αντίστοιχο αύξοντα αριθμό εγγραφής (γραμμής) στο αρχείο. Θα επιστρέφει το πλήθος των κόμβων του ΔΔΑ.
    Συνάρτηση int BuildBST(BinTreePointer *Root);
    2. Θα εμφανίζει το πλήθος των κόμβων του ΔΔΑ όπως και τους κόμβους του ΔΔΑ με αύξουσα διάταξη ως προς ΑΜ.
    3. Εισαγωγή νέων εγγραφών φοιτητών στο αρχείο foitites.dat και ενημέρωση του ΔΔΑ. Κάθε αλφαριθμητικό πεδίο όπως
    και το πεδίο φύλο (τύπου χαρακτήρας) να διαβάζονται με scanf() και στη συνέχεια getchar(). Για το φύλο δε χρειάζεται
    η να γίνεται έλεγχος εγκυρότητας θεωρούμε ότι θα δοθεί F ή Μ. Η fopen θα κληθεί με 2 παράμετρο “a” καθώς οι νέες
    εγγραφές θα προστεθούν μετά την τελευταία εγγραφή του αρχείου. Μετά από κάθε προσθήκη εγγραφής στο αρχείο θα εμφανίζετε
    το μέγεθος του αρχείου. (δείτε στο στιγμιότυπο εκτέλεσης).
    Συνάρτηση void writeNewStudents(BinTreePointer *Root, int *size);
    4. Θα εμφανίζει το πλήθος των κόμβων του ΔΔΑ όπως και τους κόμβους του ΔΔΑ με αύξουσα διάταξη ως προς ΑΜ.
    5. Αναζήτηση φοιτητή. Θα δίνεται ο ΑΜ του φοιτητή και θα τον αναζητά στο ΔΔΑ. Στη συνέχεια εφόσον υπάρχει στο ΔΔΑ
    θα τον εντοπίζει στο αρχείο “foitites.dat” και θα εμφανίζει όλες τις πληροφορίες της αντίστοιχης εγγραφής. Αν δεν
    υπάρχει στο ΔΔΑ θα εμφανίζει σχετικό μήνυμα.
    6. Θα εμφανίζει το πλήθος των κόμβων του ΔΔΑ όπως και τους κόμβους του ΔΔΑ με αύξουσα διάταξη ως προς ΑΜ.
    7. Εκτύπωση των στοιχείων όλων των φοιτητών που είναι καταχωρημένοι στο αρχείο “foitites.dat” με ΜΟ μεγαλύτερο
    από ένα δοσμένο βαθμό (πχ 0).
    Συνάρτηση void printStudentsWithGrade(float theGrade);
    Το αρχείο “foitites.dat” θα «ανοίγει» και θα «κλείνει» σε κάθε συνάρτηση που χρησιμοποιείται και με την κατάλληλη
    παράμετρο (“a” για εγγραφή στο τέλος του αρχείου ή “r” για διάβασμα των εγγραφών του αρχείου).
    Για κάθε μια από τις παραπάνω λειτουργίες εμφανίζεται στη main() σχετικό μήνυμα (Qx...)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
 int code;
 int recNo;
}BinTreeElementType;

typedef struct{
int code;
char name[20];
char surname[20];
char sex;
int year;
float grade;
}StudentT;

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
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTInorder(BinTreePointer Root);
int BuildBST(BinTreePointer *Root);
void PrintStudent(int RecNum);
void printStudentsWithGrade(float theGrade);
void writeNewstudents(BinTreePointer *Root,int *size);

int main(){
BinTreeElementType indexRec;
BinTreePointer ARoot,LocPtr;
int size; // πλήθος κόμβων του ΔΔΑ
boolean found;
float theGrade;
 // Ερώτημα 1
 printf("Q1.Build BST from  a file\n");
 size=BuildBST(&ARoot); // Δημιουργία ευρετηρίου και επιστροφή πλήθους κόμβων
 // Ερώτημα 2
 printf("Q2.Print size and BST\n");
 printf("Size=%d\n",size);
 printf("Nodes of BST\n");
 RecBSTInorder(ARoot); // Εμφάνιση των κόμβων δέντρου (σε αύξουσα διάταξη)
 // Ερώτημα 3
 printf("Q3.Write new students,update file and BST\n");
 writeNewstudents(&ARoot,&size); // Εισαγωγή νέων φοιτητών
 // Ερώτημα 4
 printf("Q4.Print size and BST\n");
 printf("Size=%d\n",size);
 RecBSTInorder(ARoot); // Εμφάνιση των κόμβων δέντρου (σε αύξουσα διάταξη)
 // Ερώτημα 5
 printf("Q5.Search for a student\n");
 printf("Give student's code?"); // Διάβασε το ΑΜ
 scanf("%d",&indexRec.code);
 RecBSTSearch(ARoot,indexRec,&found,&LocPtr); // Αναζήτησε τον φοιτητή
 if(found==TRUE){
    PrintStudent(LocPtr->Data.code);
 }else{
    printf("Student with code %d hasn't found \n",indexRec.code);
 }
 // Ερώτημα 6
 printf("Q6.print size and BST\n");
 printf("Size=%d\n",size);
 RecBSTInorder(ARoot); // Εμφάνιση των κόμβων δέντρου (σε αύξουσα διάταξη)
 // Ερώτημα 7
 printf("Q7.Print students with grades >= given grade\n");
 printf("Give the grade:");
 scanf("%f",&theGrade);
 printStudentsWithGrade(theGrade);
return 0;
}

void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data.code = Item.code;
        (*Root)->Data.recNo=Item.recNo;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else{
        if(Item.code < (*Root) ->Data.code){
            RecBSTInsert(&(*Root) ->LChild,Item);
        }else if (Item.code > (*Root) ->Data.code){
            RecBSTInsert(&(*Root) ->RChild,Item);
        }else{
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
    }
}
}


void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (KeyValue.code < Root->Data.code)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (KeyValue.code > Root->Data.code)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else{
                    *Found = TRUE;
                    *LocPtr=Root;
            }
}

 void RecBSTInorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        RecBSTInorder(Root->LChild);
        printf("(%d,%d),",Root->Data.code,Root->Data.recNo);
        RecBSTInorder(Root->RChild);
    }
}

int BuildBST(BinTreePointer *Root){
 FILE* fp;
 int nscan,size,line;
 char termch;
 StudentT student; // Εγγραφή για την ανάγνωση των στοιχείων φοιτητή από το αρχείο
 BinTreeElementType indexRec;// Εγγραφή φοιτητή για το ΔΔΑ
 CreateBST(Root);
 fp=fopen("foitites.dat","r"); // Ανοίγω αρχείο για ανάγνωση
 size=0; // Αρχικοποίηση του πλήθους εγγραφών φοιτητή
 line=0;
 if(fp == NULL) { // Αν το αρχείο δεν άνοιξε, βγάλε μήνυμα σφάλματος
   printf("Problem opening file\n");
   exit(1);
 }else{ // Αν το αρχείο άνοιξε επιτυχώς
    while(TRUE){
        nscan=fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c",&student.code,student.name,student.surname,&student.sex,&student.year,&student.grade,&termch); // Διάβασε το από το αρχείο την εγγραφή φοιτητή
        if(nscan==EOF){ // Αν έφτασε στο τέλος του αρχείου
           break;
           }
         line++; // Αύξησε το πλήθος των γραμμών
        if(nscan!=6 || termch!='\n'){ // Αν η ανάγνωση της εγγραφής δεν ήταν επιτυχής
            printf("Error in the line%d.Programm termination \n",line); // Εμφάνισε σφάλμα
        }else{
          indexRec.code=student.code; // Καταχώρησε στο indexRec τον ΑΜ που διάβασες
          indexRec.recNo=size; // Καταχώρησε στον indexRec τον τρέχοντα αριθμό εγγραφής
          RecBSTInsert(&(*Root),indexRec); // Εισαγωγή της εγγραφής του φοιτητή στο ΔΔΑ
          size++; // Αύξησε κατα 1 το πλήθος των εγγραφών
        }
    }
 }
 fclose(fp); // Κλείσε το αρχείο
 return size; // Επέστρεψε το size
}

void writeNewstudents(BinTreePointer *Root,int *size){
 FILE* fp;
 StudentT student; // εγγραφή για ανάγνωση των στοιχείων φοιτητή από το αρχείο
 BinTreeElementType indexRec; // Εγγραφή φοιτητή για το ΔΔΑ
 boolean found;
 BinTreePointer LocPtr;
 char ch;
 fp=fopen("foitites.dat","a"); //Άνοιγμα αρχείου

 if(fp == NULL){ // Αν απέτυχε να ανοίξει το αρχείο
   printf("Problem opening file");  // Μήνυμα λάθους
   exit(1);
 }else{ // Αν άνοιξε με επιτυχία
   while(TRUE){
       printf("Give student's AM?"); // Διάβασε το ΑΜ
       scanf("%d",&indexRec.code);
       RecBSTSearch(*Root,indexRec,&found,&LocPtr); // Αναζήτησε τον φοιτητή με το παραπάνω ΑΜ
       if(found==FALSE){ // Αν δε βρέθηκε
        student.code=indexRec.code; // Καταχώρησε το ΑΜ στην εγγραφή για το αρχείο
        printf("Give student's surname?"); // Διάβασε επώνυμο
        scanf("%s",student.surname);getchar();
        printf("Give student's name?"); // Διάβασε όνομα
        scanf("%s",student.name);getchar();
        printf("Give student's sexF/M?"); // Διάβασε φύλο
        scanf("%c",&student.sex);getchar();
        printf("Give student's registration year?"); // Διάβασε έτος
        scanf("%d",&student.year);
        printf("Give student's grade?"); // Διάβασε βαθμό
        scanf("%f",&student.grade);
        indexRec.recNo=*size;
        RecBSTInsert(&(*Root),indexRec); // Εισαγωγή του φοιτητή στο ΔΔΑ
        fprintf(fp,"%d,%s,%s,%c,%d,%.1f\n",student.code,student.name, student.surname,student.sex,student.year,student.grade); // Εγγραφή στο αρχείο
        (*size)++; // Αύξηση πλήθους φοιτητών κατά 1
       }else{
         printf("%d exists in file already\n",indexRec.code);
          printf("Continue Y/N:");
           do{
              scanf("%c", &ch);
             } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
        }while (toupper(ch)!='N');
   }
   fclose(fp); //Κλείσιμο αρχείου
  }
}

void PrintStudent(int recNum){
 FILE* fp;
 int nscan,lines;
 char termch;
 StudentT student; // εγγραφή για την ανάγνωση των στοιχείων του φοιτητή από το αρχείο
 fp=fopen("foitites.dat","r"); // Άνοιξε το αρχείο
 lines=0; // Αρχικοποίηση των γραμμών του αρχείου που διαβάστηκαν 
 if(fp == NULL){ // Αν δεν άνοιξε το αρχείο
  printf("Problem opening file"); // Εμφάνισε σφάλμα
 }else{  // Αν άνοιξε σωστά
    while(lines!=recNum){ // Όσο δεν έφτασε στη γραμμή του ζητούμενου φοιτητή
       nscan=fscanf(fp,"%d,%20[^,],%20[^,],%c,%d,%f%c",&student.code,student.name,student.surname,&student.sex,&student.year,&student.grade,&termch); // Διάβασε από το αρχείο την εγγραφή του φοιτητή
        if(nscan == EOF) { // Αν η ανάγνωση έφτασε στο τέλος του αρχείου
          break;
        }
         lines++; // Αύξησε το πλήθος των γραμμών
        if(nscan != 6 || termch != '\n'){  // Αν η ανάγνωση της εγγραφή δεν ήταν επιτυχής
            printf("Error in line %d.Program termination\n",lines); // Εμφάνισε λάθος
            exit(1);
   }
    if(lines==recNum+1){
     printf("%d,%s,%s,%c,%d,%.1f\n",student.code,student.name,student.surname,student.sex,student.year,student.grade); // Εμφάνισε όλα τα στοιχεία του φοιτητή
    }
   }
 }
 fclose(fp); // Κλείσιμο αρχείου
}

void printStudentsWithGrade(float theGrade){
 FILE* fp;
 int nscan,line=0;
 char termch;
 StudentT student;
 fp=fopen("foitites.dat","r"); // Ανοίγω αρχείο για ανάγνωση
 if(fp == NULL){ // Αν απέτυχε να ανοίξει το αρχείο
  printf("Problem opening file"); // Μήνυμα λάθους
 }else{ // Αν άνοιξε με επιτυχία
    while(TRUE){
         nscan=fscanf(fp,"%d,%s,%s,%c,%d,%f%c",&student.code,student.name,student.surname,&student.sex,&student.year,&student.grade,&termch); // Διάβασε το αρχείο από την εγγραφή του φοιτητή
         if(nscan == EOF){ // Αν έχει φτάσει στο τέλος του αρχείου
          break;
         }   
         line++; // Αύξησε το πλήθος των γραμμών
        if(nscan != 6 || termch != '\n'){ // Αν η ανάγνωση της εγγραφής δεν ήταν επιτυχής
            printf("Error in line %d.Program termination \n",line); // Εμφάνισε λάθος
        }else{
          if(student.grade>=theGrade){
            printf("%d,%s,%s,%c,%d,%.1f\n",student.code,student.name,student.surname,student.sex,student.year,student.grade); // Εμφάνισε τα στοιχεία του φοιτητή
          }
        }
     }     
 fclose(fp); //Κλείσιμο αρχείου
 }
}
