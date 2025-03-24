/**
 * @param {number} n
 * @param {number} w
 * @param {number} maxWeight
 * @return {number}
 */
var maxContainers = function(n, w, m) {
    if((n * n * w) <= m) return n * n;
    return Math.floor(m / w);
};