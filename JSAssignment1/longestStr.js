var array=['how are you','light','animal','longest string'];

var max=0;
var longest;

for(var i=0 ; i < array.length ; i++){
    if(array[i].length > max){
        var max=array[i].length;
        longest=array[i];
    }
}

console.log(longest);