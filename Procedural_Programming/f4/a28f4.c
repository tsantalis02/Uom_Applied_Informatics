#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int getcode();
double discount_percentage(int code);
int product_points (int code, double price);

int main (){
int code,points,total_points;
double price,discount,total_discount,final_price,total;
total_discount=0;
total=0;
total_points=0;
code=getcode();
 while (code!=0){
  printf("Dwse timh:");
  price=GetReal();
  discount=discount_percentage(code)*price;
  final_price=price -discount;
  points=product_points(code,final_price);
  total_discount+=discount;
  total+=final_price;
  total_points+=points;
  code=getcode();
 }
printf("----------------------\n");
printf("Teliko synolo: %.2f Euro\n",total);
printf("Ekptwdh: %.2f Euro\n",total_discount);
printf("Pontoi: %d\n",total_points);
return 0;}

int getcode(){
int code;
 while (TRUE){
   printf("Dwse ton kwdiko :");
   code=GetInteger();
   if (code>=0 && code<=2000){
    return code;
   }
   printf ("Lathos Kwdikos [0-2000]\n");
 }
}

double discount_percentage(int code){
    double result;
    if (code<=300){
        result=0.05;
    }else if(code<501){
       result=0.1;
    }else if(code<1001){
       result=0.15;
    }else{
       result=0.2;
    }
return result;}

int product_points(int code,double price){
    int points;
    points=1;
    if (code>=1000 && code<=1500){
        points=points+ceil(price/5);
    }
    return points;
}
