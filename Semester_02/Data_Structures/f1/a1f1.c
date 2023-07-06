/*
File:a1f1.c
Άδεια χρήσης: GNU General Public License v3.0
   
    Ένα σημαντικό πρόβλημα της θεωρίας αριθμών (του πεδίου των μαθηματικών που έχει ως αντικείμενο τη
    μελέτη των ιδιοτήτων των μη αρνητικών ακεραίων) είναι το πρόβλημα του προσδιορισμού του κατά πόσο
    ένας ακέραιος είναι πρώτος. Ένας θετικός ακέραιος n είναι πρώτος (prime) αν έχει ακριβώς δύο θετικούς
    διαιρέτες, τον εαυτό του και το 1. Οι πρώτοι αριθμοί είναι ιδιαίτερα σημαντικοί σήμερα για την
    κρυπτογραφία, αφού πολλές από τις καλύτερες τεχνικές κρυπτογράφησης βασίζονται στους πρώτους
    αριθμούς. Να γραφεί πρόγραμμα που θα περιλαμβάνει τα παρακάτω υποπρογράμματα:
    1) συνάρτηση isPrime που θα δέχεται ένα θετικό ακέραιο n και θα επιστρέφει την τιμή TRUE ή FALSE
    ανάλογα με το αν ο n είναι ή όχι αντίστοιχα πρώτος αριθμός
    2) διαδικασία createPrimeSet που θα δέχεται δύο θετικούς ακεραίους, έστω first και last, και θα
    δημιουργεί και επιστρέφει το σύνολο των πρώτων αριθμών που ανήκουν στο διάστημα [first .. last]
    3) διαδικασία displaySet που δέχεται τον πρώτο αριθμό first ενός συνόλου θετικών ακεραίων S και
    εμφανίζει τα στοιχεία του συνόλου στην ίδια γραμμή με ένα κενό χαρακτήρα μεταξύ τους.
    Στη συνέχεια, γράψτε κυρίως πρόγραμμα όπου θα διαβάζονται δύο ακέραιοι αριθμοί, έστω first και last,
    που θα πρέπει να ανήκουν στο διάστημα [2..200] και επιπλέον να ισχύει first < last. Στη συνέχεια, θα
    καλούνται οι διαδικασίες createPrimeSet και displaySet για τη δημιουργία και εμφάνιση του συνόλου των
    πρώτων αριθμών που ανήκουν στο διάστημα [first .. last].
    Να χρησιμοποιηθεί ο ΑΤΔ σύνολο με πίνακα. Η διαδικασία displaySet θα δέχεται ένα σύνολο θετικών
    ακεραίων S, τον πρώτο (first) και τον τελευταίο (last) αριθμό αυτού του συνόλου.
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define meg_plithos 201

typedef enum{
  FALSE,TRUE
}boolean;

typedef boolean typos_synolou[meg_plithos];
typedef int stoixeio_synolou ;

boolean isPrime(stoixeio_synolou n);
void createPrimeSet(stoixeio_synolou first,stoixeio_synolou last,typos_synolou S);
void displaySet(stoixeio_synolou first,stoixeio_synolou last,typos_synolou S);
void Dimiourgia(typos_synolou S);
void Eisagogi(stoixeio_synolou n,typos_synolou S);
boolean Melos(stoixeio_synolou n,typos_synolou S);

int main(){
 stoixeio_synolou first,last; //Ορισμός πρώτου και τελευταίου θετικού ακεραίου αριθμού
 typos_synolou S; // Ορισμός συνόλου
  
/* Εισαγωγή πρώτου και τελευταίου ακεραίου αριθμού. Εκτέλεση τουλάχιστον μια φορά με το do, έλεγχος να είναι ο πρώτος μεγαλύτερο ή ίσο 
από το ελάχιστο που ορίσαμε (2) ,να είναι first < last και έλεγχος να είναι ο τελευταίος μεγαλύτερο ή ίσο 
από το ελάχιστο που ορίσαμε (2) και να είναι μικρότερο ή ίσο από το ανώτερο όριο που ορίσαμε (200).
*/
  do{
    printf("Dwse ton prwto arithmo: ");
    scanf("%d",&first);
    printf("Dwse ton teleytaio arithmo: ");
    scanf("%d",&last);
  }while((first<2 || first>199) && (last>200 || last<2) && first>last);
 createPrimeSet(first,last,S); // Δημιουργείται το σύνολο πρώτων αριθμών με όρια από τον first μέχρι τον last
 displaySet(first,last,S); // Εμφάνιση του συνόλου
 return 0;
}

// Ελέγχει αν ένας αριθμός είναι πρώτος ή όχι. Ένας θετικός ακέραιος n είναι πρώτος (prime) αν έχει ακριβώς δύο θετικούς διαιρέτες, τον εαυτό του και το 1.
boolean isPrime(stoixeio_synolou n){
 stoixeio_synolou i;
  for(i=2;i<n-1;i++){
    if(n%i==0){
        return FALSE;
    }
  }
 return TRUE;
}

void createPrimeSet(stoixeio_synolou first,stoixeio_synolou last,typos_synolou S){
stoixeio_synolou i;
  Dimiourgia(S); // Δημιουργία συνόλου
  for(i=first;i<last;i++){
    if(isPrime(i)){ // Κάνει τον έλεγχο αν ο αριθμός είναι πρώτος ή όχι
        Eisagogi(i,S);// Τον τοποθετεί μέσα στο σύνολο
    }
  }
}

void displaySet(stoixeio_synolou first,stoixeio_synolou last,typos_synolou S){
stoixeio_synolou i;
  for(i=first;i<last;i++){
    if(Melos(i,S)){
        printf(" %d",i);
    }
  }
}

void Dimiourgia(typos_synolou synolo)

{
    stoixeio_synolou i;

    for (i = 0; i < meg_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou n, typos_synolou S)

{
    S[n] = TRUE;
}

boolean Melos(stoixeio_synolou n,typos_synolou S)
{
 return S[n];
}
