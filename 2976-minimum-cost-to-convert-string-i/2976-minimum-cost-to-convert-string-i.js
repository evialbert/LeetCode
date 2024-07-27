/**
 * @param {string} source
 * @param {string} target
 * @param {character[]} original
 * @param {character[]} changed
 * @param {number[]} cost
 * @return {number}
 */
var minimumCost = function(source, target, original, changed, cost) {
    const mat = Array.from({ length: 26 }, () => Array(26).fill(Infinity));
        
    for (let i = 0; i < cost.length; i++) {
        const s = original[i].charCodeAt(0) - 'a'.charCodeAt(0);
        const e = changed[i].charCodeAt(0) - 'a'.charCodeAt(0);
        mat[s][e] = Math.min(mat[s][e], cost[i]);
    }
    
    for (let i = 0; i < 26; i++) {
        mat[i][i] = 0;
    }

    for (let k = 0; k < 26; k++) {
        for (let i = 0; i < 26; i++) {
            if (mat[i][k] < Infinity) {
                for (let j = 0; j < 26; j++) {
                    if (mat[k][j] < Infinity) {
                        mat[i][j] = Math.min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }
    }
    
    let total = 0;
    for (let i = 0; i < source.length; i++) {
        const s = source[i].charCodeAt(0) - 'a'.charCodeAt(0);
        const e = target[i].charCodeAt(0) - 'a'.charCodeAt(0);
        if (s !== e) {
            if (mat[s][e] === Infinity) return -1;
            total += mat[s][e];
        }
    }
    return total;
};