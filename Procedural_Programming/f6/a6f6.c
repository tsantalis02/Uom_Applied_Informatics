/*
File:a6f6.c

Άδεια χρήσης: GNU General Public License v3.0

    Να γραφεί ένα πρόγραμμα το οποίο εμφανίζει μέσους όρους σωματομετρικών στοιχείων μιας ομάδας Ν ατόμων 
    (το Ν είναι “σταθερά” και καθορίζεται με αντίστοιχη εντολή define). Για την υποβολή της άσκησης μπορείτε 
    να θέσετε το Ν ίσο με 5. Το πρόγραμμα θα εκτελεί τις παρακάτω λειτουργίες με τη χρήση συναρτήσεων: 
    a. Θα διαβάζει Ν τετράδες ακέραιων αριθμών (σωματομετρικά στοιχεία) και θα τους καταχωρεί σε διδιάστατο 
    πίνακα (συνάρτηση readData). Κάθε τετράδα αναφέρεται στα στοιχεία ενός ατόμου, που είναι κατά σειρά τα εξής:
    1) το φύλο (0 αν είναι άνδρας, 1 αν είναι γυναίκα)
    2) το βάρος (σε κιλά, ακέραια τιμή)
    3) το ύψος (σε εκατοστά, ακέραια τιμή) 
    4) η ηλικία (σε χρόνια, ακέραια τιμή)
    b. Θα εμφανίζει το μέσο όρο του βάρους, του ύψους και της ηλικίας τόσο για τους άνδρες όσο και για τις
    γυναίκες. Ο υπολογισμός (και όχι η εμφάνιση) του μέσου όρου για κάθε ένα στοιχείο (ύψος, βάρος ηλικία) 
    θα γίνεται με τη βοήθεια μιας (και μόνο) συνάρτησης void FindMean. Εκτός των άλλων παραμέτρων που θα 
    ορίσετε στη συνάρτηση, αυτή θα έχει ως παράμετρο και έναν αριθμοδείκτη (τιμές 1, 2, 3). Ο αριθμοδείκτης 
    θα δείχνει το αντίστοιχο στοιχείο της τετράδας, του οποίου ο μέσος όρος υπολογίζεται στη συγκεκριμένη κλήση, 
    δηλαδή τη κατάλληλη στήλη του διδιάστατου πίνακα. Για παράδειγμα, όταν ο αριθμοδείκτης είναι 1, τότε θα
    υπολογίζεται ο μέσος όρος του βάρους. Η συνάρτηση FindMean σε κάθε κλήση της θα «επιστρέφει» συγχρόνως 
    τον αντίστοιχο μέσο όρο για τους άνδρες και τον αντίστοιχο μέσο όρο για τις γυναίκες, θα «επιστρέφει» 
    δηλαδή 2 τιμές. (δείτε παρατήρηση 5 για τον όρο «επιστρέφει»). Στη συνάρτηση main() θα καλούνται κατάλληλα 
    οι παραπάνω συναρτήσεις/διαδικασίες προκειμένου να διαβαστούν τα δεδομένα και στη συνέχεια να εμφανιστούν 
    οι μέσοι όροι του βάρους, του ύψους και της ηλικίας των ανδρών και των γυναικών. 
    Οι μέσοι όροι θα εμφανίζονται με ακρίβεια ενός δεκαδικού ψηφίου.
*/
#include <stdio.h>
#include "simpio.h"

#define N 5

void readData(int A[][N]);
void FindMean(int A[][N],int which_row,double *mo_mens,double *mo_womens);


int main()
{
  int A[4][N];
  double baros_andrwn,baros_gynaikwn,ypsos_andrwn,ypsos_gynaikwn,ilikia_andrwn,ilikia_gynaikwn;
  readData(A);
  FindMean(A,2,&baros_andrwn,&baros_gynaikwn);
  printf("Mesos oros barous andrwn: %.1f \n ",baros_andrwn);
  printf("Mesos oros barous gynaikwn: %.1f \n",baros_gynaikwn);
  printf("                               \n");
  FindMean(A,3,&ypsos_andrwn,&ypsos_gynaikwn);
  printf("Mesos oros ypsous andrwn: %.1f \n",ypsos_andrwn);
  printf("Mesos oros ypsous gynaikwn: %.1f \n",ypsos_gynaikwn);
  printf("                                \n");
  FindMean(A,4,&ilikia_andrwn,&ilikia_gynaikwn);
  printf("Mesos oros ilikias andrwn: %.1f \n",ilikia_andrwn);
  printf("Mesos oros ilikias gynaikwn: %.1f \n",ilikia_gynaikwn);
return 0;
}

void readData(int A[][N]){
 int i,j;
 for(j=1;j<=N;j++)
 {
    for(i=1;i<=4;i++)
    {
        switch(i)
        {
         case 1:
          printf("Dwse fylo: ");
          A[i][j]=GetInteger();
          break;
         case 2:
           printf("Dwse baros: ");
           A[i][j]=GetInteger();
           break;
         case 3:
            printf("Dwse ypsos: ");
            A[i][j]=GetInteger();
            break;
         case 4:
            printf("Dwse ilikia: ");
            A[i][j]=GetInteger();
            break;
        }
     }
      printf("-----\n");
 }
}

void FindMean(int A[][N],int which_row,double *mo_mens,double *mo_womens){
 int i,j,sum1=0,sum2=0,counter1=0,counter2=0;
 for(j=1;j<=N;j++)
 {
     if(A[1][j]==0){
        sum1=sum1+A[which_row][j];
        counter1++;
     }else{
        sum2=sum2+A[which_row][j];
        counter2++;
     }
 }
 *mo_mens=sum1/(counter1*1.0);
 *mo_womens=sum2/(counter2*1.0);
}
