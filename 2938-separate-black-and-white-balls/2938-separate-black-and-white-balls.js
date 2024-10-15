/**
 * @param {string} s
 * @return {number}
 */
var minimumSteps = function(s) {
    for(var i = 0, count = 0, j = 0; i < s.length; i++) count += s[i] === '0' ? (i - j++) : 0;
    return count;
};