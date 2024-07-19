/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var getEncryptedString = function(s, k) {
 
    var s1= s.repeat(k+1)

 
   
    var ok=''
    for(let i=0;i<s.length;i++){
         ok+=s1[i+k]
    }
    console.log(ok)
    return ok
};