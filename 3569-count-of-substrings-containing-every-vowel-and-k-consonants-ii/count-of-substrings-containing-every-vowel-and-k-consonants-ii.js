/**
 * @param {string} word
 * @param {number} k
 * @return {number}
 */
var countOfSubstrings = function(word, k) {
let frequencies = [new Array(128).fill(0), new Array(128).fill(0)];
    "aeiou".split("").forEach(v => frequencies[0][v.charCodeAt(0)] = 1);

    let response = 0, currentK = 0, vowels = 0, extraLeft = 0, left = 0;

    for (let right = 0; right < word.length; right++) {
        let rightChar = word[right].charCodeAt(0);

        if (frequencies[0][rightChar] === 1) {
            if (++frequencies[1][rightChar] === 1) vowels++;
        } else {
            currentK++;
        }

        while (currentK > k) {
            let leftChar = word[left].charCodeAt(0);
            if (frequencies[0][leftChar] === 1) {
                if (--frequencies[1][leftChar] === 0) vowels--;
            } else {
                currentK--;
            }
            left++;
            extraLeft = 0;
        }

        while (vowels === 5 && currentK === k && left < right && frequencies[0][word[left].charCodeAt(0)] === 1 && frequencies[1][word[left].charCodeAt(0)] > 1) {
            extraLeft++;
            frequencies[1][word[left].charCodeAt(0)]--;
            left++;
        }

        if (currentK === k && vowels === 5) {
            response += (1 + extraLeft);
        }
    }

    return response;
};