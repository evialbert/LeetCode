/**
 * @param {string} s
 * @return {number}
 */
var minimumChairs = function(s) {
    let count = 0;
    let ca = 0;
    for(let char of s){
        if(char === 'E') {
            (ca <= 0) ? count++ : ca--;
        }
        if(char === 'L') {
            ca++;
        };
    }
    return count;  
}; 