/**
 * @param {number[]} nums
 * @return {number}
 */
const subsetXORSum = f = (n, i = 0, s = 0) =>
    n[i] ? f(n, i + 1, s ^ n[i]) + f(n, i + 1, s) : s;