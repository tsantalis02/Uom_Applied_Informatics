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
stoixeio_synolou first,last;
typos_synolou S;
do{
printf("Dwse ton prwto arithmo: ");
scanf("%d",&first);
printf("Dwse ton teleytaio arithmo: ");
scanf("%d",&last);
}while((first<2 || first>199) && (last>200 || last<2) && first>last);
createPrimeSet(first,last,S);
displaySet(first,last,S);
return 0;}


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
  Dimiourgia(S);
  for(i=first;i<last;i++){
    if(isPrime(i)){
        Eisagogi(i,S);
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
