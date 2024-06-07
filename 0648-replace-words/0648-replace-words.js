/**
 * @param {string[]} dictionary
 * @param {string} sentence
 * @return {string}
 */
var replaceWords = function(dictionary, sentence) {
    const split_sent = sentence.split(' ')
    
    for(let i=0; i<dictionary.length; ++i){
        const dic_len = dictionary[i].length
        for(let j=0; j<split_sent.length; ++j){
            if(split_sent[j].slice(0, dic_len) === dictionary[i]){
                split_sent.splice(j, 1, dictionary[i])
            }
        }
    }

    return split_sent.join(' ')
};