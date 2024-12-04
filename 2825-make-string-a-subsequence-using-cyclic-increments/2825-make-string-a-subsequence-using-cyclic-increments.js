/**
 * @param {string} str1
 * @param {string} str2
 * @return {boolean}
 */
var canMakeSubsequence = function (str1, str2) {
    j = 0;
    for (let i = 0; i < str1.length; i++) {
        const code = str1.charCodeAt(i);
        const codeToMatch = str2.charCodeAt(j);
        if (code === str2.charCodeAt(j) || (code + 1 > 122 ? 97 : code + 1) === str2.charCodeAt(j)) {
            j++;
            if (j === str2.length) return true
        }
    }
    return false;

};