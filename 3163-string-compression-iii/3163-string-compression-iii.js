/**
 * @param {string} word
 * @return {string}
 */
var compressedString = function(word) {
    word += "&"
    let r = ""
    let c = 1
    for(let i = 1; i < word.length; i++, c++) {
        if (word[i-1] !== word[i] || c === 9) {
            r += c + word[i-1]
            c = 0
        }
    }
    return r
};