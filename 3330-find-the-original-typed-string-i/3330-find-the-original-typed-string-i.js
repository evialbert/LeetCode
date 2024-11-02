/**
 * @param {string} word
 * @return {number}
 */
var possibleStringCount = function(word) {
    counter = 1
    for (let i = 1; i < word.length; i++) {
        if(word[i] === word[i - 1]){
            counter++
        }
    }
    return counter
};