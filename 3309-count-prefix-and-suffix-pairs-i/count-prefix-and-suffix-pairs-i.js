/**
 * @param {string[]} words
 * @return {number}
 */
var countPrefixSuffixPairs = function (words) {
  let result = 0;

  for (let i = 0; i < words.length; i++) {
    const word = words[i];

    for (let j = i + 1; j < words.length; j++) {
      const second = words[j];

      if (second.startsWith(word) && second.endsWith(word)) {
        result++;
      }
    }
  }

  return result;
};