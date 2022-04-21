/*
File:126f4.c

Άδεια χρήσης: GNU General Public License v3.0

Να δημιουργήσετε τις συναρτήσεις f() και g() , οι οποίες ορίζονται από τους παρακάτω μαθηματικούς τύπους,
    οι οποίες θα πρέπει να υλοποιηθούν ως συναρτήσεις στην γλώσσα C:
      	f (x)= x+2 , x>0                       g( x,y )= x− y, x> 0 και y> 0
      	f (x)= −3x+7 , x<=0                    g( x,y )= 7x−5 , αλλιώς
    Οι τιμές των παραμέτρων x,y στις παραπάνω συναρτήσεις είναι ακέραιες (int). Ο τύπος των συναρτήσεων θα καθοριστεί από εσάς.
    Να υλοποιηθεί πρόγραμμα το οποίο ζητά από τον χρήστη τις παραμέτρους x και y, και έπειτα εμφανίζει
    (α) το αποτέλεσμα της συνάρτησης f(x),
    (β) το αποτέλεσμα της συνάρτησης g(x,y) και το αποτέλεσμα της συνάρτησης f(g(x)), όπως φαίνονται στα ακόλουθα παραδείγματα εκτέλεσης.
    Η εμφάνιση των αποτελεσμάτων θα γίνεται μέσω του κυρίως προγράμματος (συνάρτηση main(), δηλαδή η εντολή εμφάνισης των αποτελεσμάτων
    (printf) θα είναι στην main()).
*/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int ypof(int x);
int ypog(int x,int y);
int yposin(int x, int y);

int main(){
 int x,y;
 printf("Enter x:");
 x=GetInteger();
 printf("Enter y:");
 y=GetInteger();
 printf("f(x)=f(%d)=%d\n",x,ypof(x));
 printf("g(x,y)=g(%d,%d)=%d\n",x,y,ypog(x,y));
 printf("f(g(x,y))=f(g(%d,%d))=%d\n",x,y,yposin(x,y));
 return 0;}

 int ypof(int x){
  if (x>0){
    return x+2;
  }else{
   return -3*x+7;
  }
 }

 int ypog(int x,int y){
  if(x>0 && y>0){
    return x-y;
  }else{
    return 7*x-5;
  }
 }

 int yposin(int x,int y){
  if (x>0 && y>0){
    return x-y+2;
  }else if(x>0 && y<0){
      return 7*x-3;
  }else {
    return -21*x+22;
  }
 }
