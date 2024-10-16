/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {string}
 */
var longestDiverseString = function(a, b, c, prev=null) {
    let s = ''
    let biggest = null
    
    if (a >= b && a >= c && prev !== 'a' && a !== 0) biggest = 'a'
    if (b >= a && b >= c && prev !== 'b' && b !== 0) biggest = 'b'
    if (c >= a && c >= b && prev !== 'c' && c !== 0) biggest = 'c'
    
    if (biggest === 'a' && prev !== 'a') {
        let count = Math.min(2, a)
        s += 'a'.repeat(count) + longestDiverseString(a-count, b, c, 'a')
        
    } else if (biggest === 'b' && prev !== 'b') {
        let count = Math.min(2, b)
        s += 'b'.repeat(count) + longestDiverseString(a, b-count, c, 'b')
        
    } else if (biggest === 'c' && prev !== 'c') {
        let count = Math.min(2, c)
        s += 'c'.repeat(count) + longestDiverseString(a, b, c-count, 'c')
        
    } else if (prev !== 'c' && c > 0) s+= 'c' + longestDiverseString(a, b, c-1, 'c')   
    else if (prev !== 'b' && b > 0) s+= 'b' + longestDiverseString(a, b-1, c, 'b')
    else if (prev !== 'a' && a > 0) s+= 'a' + longestDiverseString(a-1, b, c, 'a')
        
    return s  
};