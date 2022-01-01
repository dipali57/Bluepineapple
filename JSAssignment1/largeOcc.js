var str = 'hello chaitaliii';
var freq = {};
var max ='';
for(var i = 0; i < str.length; i++)
{
    var key = str[i];
    if(!freq[key]){
     freq[key] = 0;
    }
    freq[key]++;
    if(max == '' || freq[key] > freq[max]){
        max = key;
    }
}
console.log("character "+max +" occures " + freq[max]+" times ");