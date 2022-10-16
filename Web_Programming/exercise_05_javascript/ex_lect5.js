console.log('"1η άσκηση"');
for(i=1;i<11;i++){
    console.log(""+i+"η δύναμη του 2:"+2**i);
}
console.log('"2η άσκηση"');
console.log('"Κλήση συνάρτησης με ορίσματα: 10,14,9"');
var comparator = function(a, b, c){
   if(a > b && a>c){
       return a;
   }
   if(a > b && a < c){
       return c;
   }
   if(a < b && b > c){
       return b;
   }
   if(a < b && b < c){
       return c;
   }
}
console.log(comparator(10,14,9));
console.log("Κλήση συνάρτησης με ορίσματα: "+'aa'+',ba'+',ca');
console.log(comparator('aa','ba','ca'));
console.log('"3η άσκηση"');
var power = function(a,b){
   if(a > 0 && b > 0){
    if(a % 1 == 0 && b % 1 == 0){
           return a**b;
    }
   }else{
       return undefined;
   }
}
console.log('"Κλήση συνάρτησης με ορίσματα: 3,3"');
console.log(power(3,3));
console.log('"Κλήση συνάρτησης με ορίσματα: 3.2,3"');
console.log(power(3.2,3));
console.log('"Κλήση συνάρτησης με ορίσματα: -3,3"');
console.log(power(-3,3));
console.log("Κλήση συνάρτησης με ορίσματα: 'aa','ba'");
console.log(power('aa','ba'));