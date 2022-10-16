
document.getElementById('calculate').addEventListener('click',function(evt){
    var res = document.getElementById('result');
    var n1 = document.getElementById('n01').value;
    var n2 = document.getElementById('n02').value;
    if(isNaN(n1)){
      var num1=NaN;
    }else{
      num1 = Number.parseInt(n1);
    }
    if(isNaN(n2)){
      var num2=NaN;
    }else{
      num2 = Number.parseInt(n2);
    }
    var operation = document.querySelector('select');
     switch(operation.value){
        case'plus':
         result = num1+num2;
         break;
        case 'minus':
           result = num1-num2;
           break;
        case 'times':
             result = num1*num2;
             break;
        case 'divide': 
           if(num2==0){
               result = Infinity;   
           }else{
                result = num1/num2;
           } 
           break;
         }   
     res.insertAdjacentHTML('beforeend',result);
    });
    
    
    