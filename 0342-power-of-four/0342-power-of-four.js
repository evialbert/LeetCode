/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfFour = function(n) {
    if (n <= 0) return false;
    let root = Math.floor(Math.log(n) / Math.log(4));
    if(Math.pow(4,root) == n) return true;
    else return false;
};