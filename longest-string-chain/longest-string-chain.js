/**
 * @param {string[]} words
 * @return {number}
 */
var longestStrChain = function(words) {
    let wordMap = {}
    let maxChainLength = 1
    
    words.forEach(word => {
        if (!(word.length in wordMap)) wordMap[word.length] = []
        wordMap[word.length].push(new WordTreeNode(word))
    })
    
    Object.keys(wordMap).reverse().forEach((length, index) => {
        let parents = wordMap[length]
        let children = wordMap[length - 1]
        
        if (!children) return
        
        parents.forEach((parent) => {
            children.forEach((child) => {
                if(checkPredeccesor(child.value, parent.value)) {
                    parent.children.push(child)
                    child.lengthOfChain = Math.max(parent.lengthOfChain + 1, child.lengthOfChain)
                    maxChainLength = Math.max(maxChainLength, child.lengthOfChain)
                }
            })
        })
    })
 
    return maxChainLength
}

var WordTreeNode = function(value) {
    this.value = value
    this.children = []
    this.lengthOfChain = 1
}

// assuming that word1 is always smaller than word2
var checkPredeccesor = function(word1, word2) {
    if (word1.length + 1 !== word2.length) return false
    
    let skip = 0
    let i = 0, j = 0
    
    while (i < word1.length && j < word2.length) {
        if (word1[i] !== word2[j] && skip < 1) {
            skip++
            j++
            continue
        }
        
        if (word1[i] !== word2[j] && skip === 1) {
            return false
        }
        
        i++
        j++
    }
    
    return true
}