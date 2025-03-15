/**
 * @param {number} upper
 * @param {number} lower
 * @param {number[]} colsum
 * @return {number[][]}
 */
var reconstructMatrix = function(upper, lower, colsum) {
    const len = colsum.length;
    const ret = [new Uint8Array(len), new Uint8Array(len)];
    for (let i = 0; i < len; ++i) {
        if (colsum[i] === 0 || colsum[i] === 1) {
            continue;
        }
        if (upper < 0 || lower < 0) {
            return [];
        }
        --upper;
        --lower;
        ++ret[0][i];
        ++ret[1][i];
    }
    for (let i = 0; i < len; ++i) {
        if (colsum[i] === 0 || colsum[i] === 2) {
            continue;
        }
        if (upper < 0 || lower < 0) {
            return [];
        }
        upper > 0 ? (--upper, ++ret[0][i]) : (--lower, ++ret[1][i]);
    }
    return upper + lower === 0 ? ret : [];
};