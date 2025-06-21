/**
 * @param {string} word
 * @param {number} k
 * @return {number}
 */
var minimumDeletions = function (word, k) {
    const freq = new Int32Array(26);
    const aCode = 'a'.charCodeAt(0);
    
    for (let i = 0; i < word.length; i++) {
        freq[word.charCodeAt(i) - aCode]++;
    }

    const counts = freq.filter(f => f > 0).sort((a, b) => a - b);
    const n = counts.length;
    const suffixSum = new Int32Array(n + 1);

    for (let i = n - 1; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + counts[i];
    }

    let best = suffixSum[0];
    let deleted = 0;

    for (let i = 0, j = 0; i < n; i++) {
        while (j + 1 < n && counts[j + 1] - counts[i] <= k) j++;
        const rightPartSize = n - (j + 1);
        const rightExcess = suffixSum[j + 1] - (counts[i] + k) * rightPartSize;
        best = Math.min(best, rightExcess + deleted);
        deleted += counts[i];
    }

    return best;
};