/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var appendCharacters = function(s, t) {
    let tChar = 0;
    for (let i = 0; i < t.length || i < s.length; i++) {
        if (s[i] === t[tChar]) {
            tChar += 1;
        }
    }
    return t.length - tChar;
};