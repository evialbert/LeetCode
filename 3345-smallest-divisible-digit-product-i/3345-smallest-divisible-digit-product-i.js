/**
 * @param {number} n
 * @param {number} t
 * @return {number}
 */
var smallestNumber = function (n, t) {
    const n1 = n % 10;
    if (!n1) return n; // if n ends with 0.
    const n10 = Math.floor(n / 10) || 1; // if n < 10, add 10 to it.

    for (let i = 0; i < 10 - n1; i++) {
        if (!((n10 * (n1 + i)) % t)) return n + i;
    }

    return n + 10 - n1; // closest number to n, that ends with 0.
};