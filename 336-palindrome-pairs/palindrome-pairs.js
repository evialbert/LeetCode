/**
 * @param {string[]} words
 * @return {number[][]}
 */
var palindromePairs = function(words) {
    let Trie = function() {
        this.palins = []; // palindromes after this node
        this.next = {};
        this.index = -1; 
    }

    Trie.prototype.add2Trie = function(word, index) {
        let root = this;
        for (let i=word.length-1;i>=0;i--) {
            if (!root.next[word[i]]) root.next[word[i]] = new Trie(); // initialize
            if (isPalin(word, 0, i)) root.palins.push(index);
            root = root.next[word[i]];
        }
        root.index = index;
    }

    function searchPalin(base, trie) {
        let output = [];
        // case 1
        while (base) {
            if (trie.index >= 0 && isPalin(base, 0, base.length-1)) output.push(trie.index) // checks left over string
            trie = trie.next[base[0]]; // move to the next node
            if (!trie) return output;
            base = base.slice(1);
        }
        // target is reversed base
        if (trie.index >= 0) output.push(trie.index);
        
        // case 2
        output.push(...trie.palins);
        return output;
    }

    function isPalin(word, i, j) {
        while (i < j) if (word[i++]!=word[j--]) return false;
        return true;
    }

    let trie = new Trie();
    let res = [];
    for (let i=0; i<words.length;i++) trie.add2Trie(words[i], i);

    for (let i=0; i<words.length; i++) {
        let candidates = searchPalin(words[i], trie);
        for (let c of candidates) if (i != c) res.push([i, c]);
    }

    return res;
}