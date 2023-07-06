/*
File:a12f3.c
    
    Άδεια χρήσης: GNU General Public License v3.0
    
    Σε μία τράπεζα κάθε πελάτης εισέρχεται σ’ αυτήν μία ορισμένη χρονική στιγμή έστω την ώρα A και παραμένει
    κάποιο χρονικό διάστημα έστω Τ, προκειμένου να διεκπεραιώσει την εργασία του (ανάληψη, μεταφορά, δάνειο κλπ). 
    Δεδομένου ότι υπάρχει μόνο ένας ταμίας, εάν κάποιος πελάτης εισέλθει ενώ δεν έχει τελειώσει ο προηγούμενος, 
    η εξυπηρέτησή του αρχίζει αμέσως μόλις τελειώσει ο προηγούμενος. Γράψτε πρόγραμμα το οποίο μοντελοποιεί το 
    σύστημα εξυπηρέτησης της τράπεζας, χρησιμοποιώντας τον ΑΤΔ ουρά. Κάθε πελάτης που εισέρχεται στην τράπεζα 
    μπαίνει σε μια ουρά αναμονής. Για κάθε πελάτη μας ενδιαφέρει να γνωρίζουμε το χρόνο άφιξης, τη διάρκεια παραμονής, 
    την ώρα έναρξης, την ώρα λήξης της εξυπηρέτησης. Ο μέγιστος αριθμός πελατών που καταχωρούνται στην ουρά αναμονής είναι 3. 
    Το πρόγραμμα θα διαβάζει για κάθε πελάτη την ώρα άφιξης και τον χρόνο παραμονής με τη μορφή ώραΆφιξης, χρόνοςΠαραμονής. 
    Η ώρα άφιξης και ο χρόνος παραμονής μπορούν να είναι οποιοδήποτε θετικό μέγεθος.
    Υλοποιήστε 3 συναρτήσεις:
    
    1. Συνάρτηση που θα διαβάζει την ώρα άφιξης και τον χρόνο παραμονής του κάθε πελάτη με τη μορφή ώραΆφιξης, χρόνοςΠαραμονής 
    και θα εισάγει τον πελάτη στην ουρά αναμονής. Για την ώρα έναρξης και ώρα λήξης θα καταχωρείται η «εικονική» τιμή -1 
    (η εισαγωγή των πελατών στην ουρά αναμονής θεωρήστε τι συμβαίνει τη χρονική στιγμή που εισέρχεται στην τράπεζα). 
    Η συνάρτηση θα είναι void με παράμετρο την ουρά αναμονής. 
    
    2. Συνάρτηση η οποία προσομοιώνει την εξυπηρέτηση των πελατών. Εξάγει έναν-έναν τον πελάτη από την ουρά αναμονής και 
    για κάθε πελάτη που εξυπηρετείται θα υπολογίζει την ώρα έναρξης και λήξης της εξυπηρέτησης και θα καταχωρεί τον πελάτη 
    στην ουρά εξυπηρετηθέντων (νέα ουρά). Η ώρα έναρξης της εξυπηρέτησης των πελατών είναι ο χρόνος άφιξης του πρώτου πελάτη 
    (δες στο στιγμιότυπο εκτέλεσης). Η συνάρτηση έχει μια παράμετρο την ουρά αναμονής και επιστρέφει την ουρά των εξυπηρετηθέντων. 
    Το πρωτότυπο της συνάρτησης είναι
    QueueType TimesInQueue(QueueType *Queue)
    3. Συνάρτηση με 2 παραμέτρους: την ονομασία της ουράς, και την ουρά. Αν η ουρά δεν είναι άδεια θα εμφανίζει για κάθε πελάτη 
    τις καταχωρημένες πληροφορίες, ενώ αν είναι άδεια θα εμφανίζει σχετικό μήνυμα (δες στο στιγμιότυπο εκτέλεσης).

*/
#include <stdio.h>

#define QueueLimit 4 //το όριο μεγέθους της ουράς

typedef struct {
    int arrival,stay,start,end;
}QueueElementType; /* ο τύπος δεδομένων των στοιχείων της ουράς χρόνοι έναρξης άφιξης και αναμονής, έναρξης και λήξης εξυπηρέτησης */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void ReadData(QueueType *Queue);
QueueType TimesInQueue(QueueType *Queue);
void PrintData(QueueType *Queue);
void TraverseQ(boolean flag,QueueType Queue);

int main(){
  QueueType QW,QS; // Δήλωση ουράς αναμονής και ουράς εξυπηρέτησης
  int i;
  CreateQ(&QW); // Δημιουργία ουράς αναμονής
  // Εισαγωγή δεδομένων στην ουρά αναμονής. Χρήση συνάρτησης ReadData
   for(i=0;i<QueueLimit-1;i++){
     printf("Give: arrival time,stay time for client %d: ",i+1);
     ReadData(&QW);
   }
  TraverseQ(TRUE,QW); // Εκτύπωση της ουράς αναμονής
  QS=TimesInQueue(&QW); // Ανάθεση στην ουρά εξυπηρέτησης. Χρήση της συνάρτησης TimesInQueue
  TraverseQ(TRUE,QW); // Εκτύπωση της ουράς αναμονής (θεωρητικά δεν υπάρχει γιατί εξυπηρετήθηκαν όλοι)
  TraverseQ(FALSE,QS); // Εκτύπωση της ουράς πελατών που εξυπηρετήθηκαν
  return 0;
}

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue");
}

void ReadData(QueueType *Queue)
{
  QueueElementType Queuetmp; // Δημιουργία τύπου πελάτης
   scanf("%d,%d",&Queuetmp.arrival,&Queuetmp.stay); // Εισαγωγή χρόνου άφιξης και χρόνου αναμονής
   Queuetmp.start=-1; // Αρχικοποίηση χρόνου έναρξης εξυπηρέτησης σε -1
   Queuetmp.end=-1; // Αρχικοποίηση χρόνου λήξης εξυπηρέτησης σε -1
   AddQ(&(*Queue),Queuetmp); // Προσθήκη του πελάτη στην ουρά που εισήχθη ως όρισμα
}

QueueType TimesInQueue(QueueType *Queue){
 int earliestStart=0,currentStart=0,currentEnd=0;// Αρχικοποίηση
 QueueType QueueServiced; // Δήλωση ουράς εξυπηρετηθέντων
 QueueElementType CurrentQueue; // Δήλωση τύπου τρέχοντα πελάτη
  CreateQ(&QueueServiced); // Δημιουργία ουράς εξυπηρετηθέντων
   while(!EmptyQ(*Queue)){ // Όσο η ουρά δεν είναι άδεια
     RemoveQ(&(*Queue),&CurrentQueue); // Αφαίρεσε από την ουρά τον πρώτο πελάτη και ανέθεσε την τιμή στον τρέχοντα πελάτη
     if(CurrentQueue.arrival>earliestStart){ // Εάν ο χρόνος άφιξης είναι μετά το χρόνο εκυπηρέτησης
        currentStart=CurrentQueue.arrival; // Θέσε την τρέχουσα ώρα έναρξης ίση με την ώρα άφιξης πελάτη
     }else{
       currentStart=earliestStart;// Θέσε την τρέχουσα ώρα έναρξης ίση με τον χρόνο έναρξης εξυπηρέτησης
     }
    currentEnd=currentStart+CurrentQueue.stay; // Ενημέρωσε την ώρα λήξης εξυπηρέτησης για τον τρέχοντα πελάτη (τρέχουσα ώρα έναρξης+χρόνος παραμονής)
    earliestStart=currentEnd; // Ενημέρωσε τον χρόνο έναρξης εξυπηρέτησης για τον επόμενο πελάτη (χρόνος λήξης τρέχοντα πελάτη)
    CurrentQueue.start=currentStart; // Ενημέρωσε και τους χρόνους στον τύπο
    CurrentQueue.end=currentEnd; // Ενημέρωσε και τους χρόνους στον τύπο
    AddQ(&QueueServiced,CurrentQueue); // Εισαγωγή του τρέχοντα πελάτη στην ουρά εξυπηρετηθέντων
    }
 return QueueServiced; // Επιστροφή ουράς εξυπηρετηθέντων
}

 void TraverseQ(boolean flag,QueueType Queue) {
	int current; // Μετρητής θέσης στην ουρά
	int i=0; // Μετρητής για εμφάνιση πελάτη
	if(!EmptyQ(Queue)){ // Αν η ουρά δεν είναι άδεια
	  if(flag){
        printf("\n Waiting Queue \n");
	  }else{
	    printf("\n Service Queue \n");
	  }
	  current = Queue.Front; // Θέσε τον μετρητή στην αρχή της ουράς
	  printf("Client   \t\tStart\tEnd\tArrival\tStay\n");
	while (current != Queue.Rear) {
        printf("Client %d\t\t%d\t%d\t%d\t%d\n ",i+1,Queue.Element[current].start,Queue.Element[current].end,Queue.Element[current].arrival,Queue.Element[current].stay);
		current = (current + 1) % QueueLimit; // Αύξησε μετρητή
		i+=1; // Αύξησε μετρητή
	}
	}else{
	    if(flag){
           printf("Waiting Queue is empty\n"); // Εκτύπωσε ότι η ουρά είναι άδεια
	    }else{
	      printf("Service Queue is empty\n");
	    }
	}
}


