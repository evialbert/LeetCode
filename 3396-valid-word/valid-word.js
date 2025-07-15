/**
 * @param {string} word
 * @return {boolean}
 */

function isVowel(ch){
    return "aeiouAEIOU".includes(ch);
}

function isLetter(ch) {
  return /^[a-z]$/i.test(ch);
}

function isDigit(ch) {
  return /^[0-9]$/.test(ch);
}

function isConsonant(ch){
    return (isLetter(ch) && !isVowel(ch)) ;
}



var isValid = function(word) {
return     /^[A-Za-z0-9]{3,}$/.test(word) &&       
  /[aeiou]/i.test(word) &&               
  /[b-df-hj-np-tv-z]/i.test(word); 


// Second Solution
//     if (word.length < 3) return false;

//     let char = 0;
//     let hasVowel = false;
//     let hasConsonant = false;

//     for(let i=0; i <word.length ; i++){
//         if(isVowel(word[i])) {
//             hasVowel= true;
//             char +=1;
//         } else if(isConsonant(word[i])){
//             hasConsonant = true ;
//             char += 1;
//         }else if (isDigit(word[i])){
//             char  +=1;
 
//         }
//          else {
//             return false
//         }
//     }

//     console.log("---char--->",char)
//     if(char > 2 &&  hasVowel &&hasConsonant){
//         return true;
//     }
// return false;

};