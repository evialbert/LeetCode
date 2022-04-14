/**
 * @param {string} sequence
 * @param {string} word
 * @return {number}
 */
var maxRepeating = function(sequence, word) {
    let count = 0;
    let str = word;
    while (sequence.includes(str)) {
        count++;
        str += word;
    }
    return count;
};