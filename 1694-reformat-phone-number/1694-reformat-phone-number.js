/**
 * @param {string} number
 * @return {string}
 */
var reformatNumber = function(number) {
   let s=''; let count=0;
   for(let i of number){
     if(i!=='-' && i!==' '){
        if(count===3){count=1; s+='-'+i;}
        else{s+=i; count++;}
     }
   }
   if(s[s.length-2]==='-'){
       return s.slice(0,-3)+'-'+s[s.length-3]+s[s.length-1];
   } 
   return s; 
};