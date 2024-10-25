/**
 * @param {string} s
 * @param {character} c
 * @return {number}
 */
var countSubstrings = function(s, c) {
    let x = 0;
    for (let i = 0 ; i < s.length; i++) {
        if (s[i] === c) x++;
    }
    return (x * (x-1))/2 + x;
};