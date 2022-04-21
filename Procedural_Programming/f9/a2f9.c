/*
File:a2f9.c

Άδεια χρήσης: GNU General Public License v3.0

    Δίνεται το αρχείο κειμένου ‘i2f9.dat’ των μαθητών ενός σχολείου που περιλαμβάνει τα εξής στοιχεία για κάθε μαθητή:
    * ονοματεπώνυμο μαθητή, το οποίο δεν μπορεί να περιλαμβάνει περισσότερους από 30 χαρακτήρες
    * αριθμός απουσιών (int)
    * διάφορα στοιχεία μαθητή, τα οποία δεν μπορούν να ξεπερνάνε τους 68 χαρακτήρες
    Τα παραπάνω στοιχεία για κάθε μαθητή χωρίζονται με κόμμα.
    Ζητείται να γίνει πρόγραμμα που να δημιουργεί αρχείο μαθητών με απουσίες άνω των 100. Το πρόγραμμα
    θα ζητά τα ονόματα των αρχείων "εισόδου" (i2f9.dat) και "εξόδου" (o2f9.dat) από τον χρήστη. Από
    το αρχείο μαθητών ‘i2f9.dat’ θα δημιουργείται το αρχείο κειμένου ‘o2f9.dat’ που θα περιέχει το
    ονοματεπώνυμο (30 χαρακτήρες) και τον αριθμό απουσιών (int) κάθε μαθητή που οι απουσίες του
    ξεπερνούν τις 100. Τέλος, θα περιέχει το πλήθος όλων των μαθητών του σχολείου καθώς και το πλήθος των
    μαθητών του σχολείου που οι απουσίες τους ξεπερνούν τις 100. H εμφάνιση θα ακολουθεί στοίχιση με την
    παρακάτω μορφή:
    Το αρχείο i2f9.dat σας δίνεται και είναι το παρακάτω.
    Το αρχείο o2f9.dat που θα δημιουργηθεί
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 100
typedef enum {
    FALSE, TRUE
} boolean;
typedef struct{
   char name[30];
   int apousies;
}studentT;

void readInput(FILE* infile,studentT students[],int *pApousies,int *pStudents);
void writeOutput(FILE* outfile,int size,studentT students[],int total);

int main(){
  FILE* infile;
  FILE* outfile;

  infile = fopen("i2f9.dat","r");
  if(infile==NULL){
    printf("Cannot open input file i2f9.dat\n");
    exit(1);
  }

   outfile = fopen("o2f9.dat","w");

   studentT students[M];
   int numberofStudents,numberofApousies;
   readInput(infile,students,&numberofApousies,&numberofStudents);
    
  /* Υπολογισμοί - Έξοδος σε αρχείο */ 
   writeOutput(stdout,numberofApousies,students,numberofStudents);

 /* Κλείσιμο αρχείων */   
   fclose(infile);
   fclose(outfile);

  return 0;
}

/* Συνάρτηση ανάγνωσης δεδομένω πηγαίου αρχείου */
void readInput(FILE* infile,studentT students[],int *pApousies,int *pStudents){
  int nscan,apousies,line;
  char name[30],comments[68],termch;

  *pApousies=0;
  *pStudents=0;
  line=0;

  while(TRUE){
    nscan=fscanf(infile, "%30[^,], %d, %68[^\n]%c",name, &apousies, comments, &termch);
    if(nscan == EOF) break;
    line++;
    if(nscan != 4 || termch != '\n'){
        printf("Error in line %d.Program termination\n",line);
        exit(1);
    }
   if(apousies > 100){
      strcpy(students[*pApousies].name,name);
      students[*pApousies].apousies = apousies;
      (*pApousies)++;
   }
   (*pStudents)++;
  }
}

/* Συνάρτηση εξαγωγής επεξεργασμένων δεδομένων σε αρχείο */
 void writeOutput(FILE* outfile,int size,studentT students[],int total){
   int i;

   fprintf(outfile, "%-30s%-9s\n", "ONOMATEPWNYMO", "APOYSIES");
   for(i=0;i<39;i++){
    fputc('-',outfile);
   }
   fputc('\n',outfile);

   for(i=0;i<size;i++){
     fprintf(outfile, "%-30s%9d\n",students[i].name,students[i].apousies);
   }

  for(i=0;i<39;i++){
    fputc('-',outfile);
   }
   fputc('\n',outfile);

   fprintf(outfile, "%-30s%9d\n", "SYNOLO MATHITWN", total);
   fprintf(outfile, "%-30s%9d\n", "SYNOLO APONTWN", size);

 }
