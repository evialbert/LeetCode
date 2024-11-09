/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let result = 0;
    const mem = new Set();
    for(let i=0; i<s.length; i++) {
        if(mem.has(s[i])) {
            result+=2;
            mem.delete(s[i]);
        } else { 
            mem.add(s[i]);
        }
    };
    return result + (mem.size > 0 ? 1 : 0);
};