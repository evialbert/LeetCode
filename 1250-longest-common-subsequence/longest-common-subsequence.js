/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */
var longestCommonSubsequence = function(text1, text2) {
    
    
    
//    const dp = []
   let cur = []
   let prev = []

   for(i=0;i<=text2.length;i++){
       prev[i] = 0
       cur[i] = 0
   }

   for(let i=text1.length-1;i>=0;i--){

       for(let j=text2.length-1;j>=0;j--){

           if(text1[i]===text2[j]){
               cur[j] = 1 + prev[j+1]
           }else{
               cur[j] = Math.max(prev[j],cur[j+1])
           }

       }
       prev = [...cur]

   }

    return cur[0]
    
};