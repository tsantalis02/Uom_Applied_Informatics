document.getElementById('yelBack').onclick = function(evt){
    document.body.style.backgroundColor = 'yellow';
}
document.getElementById('whiBack').onclick = function(evt){
    document.body.style.backgroundColor = 'white';
} 
const button1 = document.getElementById('yelPar');
button1.addEventListener('click',function(evt){
    document.querySelector('p').style.backgroundColor = 'yellow';
})
const button2 = document.getElementById('whiPar');
button2.addEventListener('click',function(evt){
    document.querySelector('p').style.backgroundColor = 'white';
})

