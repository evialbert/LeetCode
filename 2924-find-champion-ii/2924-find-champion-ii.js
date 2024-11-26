/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var findChampion = function(n, edges) {
    const candidates = new Set(new Array(n).fill(0).map((_, i) => i));
    edges.forEach(([_winner, looser]) => candidates.delete(looser));
    return candidates.size === 1 ? [...candidates][0] : -1;
};