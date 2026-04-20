/**
 * @param {number} n
 * @return {number}
 */
var minCost = function(n) {
    if(n == 1 || n == 2) return n -1
    if(n == 3) return n
    let ans = 1.0

    for(let i = 4; i <= n; i+=1) {
        ans += .5
    }

    return ans * n
};