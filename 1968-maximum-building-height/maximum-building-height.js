/**
 * @param {number} n
 * @param {number[][]} restrictions
 * @return {number}
 */
var maxBuilding = function(n, restrictions) {
    // Add edge restrictions
    restrictions.push([1, 0]);
    restrictions.push([n, n - 1]);

    // Sort by distance from start (id)
    restrictions.sort(([v1], [v2]) => v1 - v2);

    // If you went incrementing from left to right, what is the height you can set for each point,
    // considering its own restriction.
    for(let i = 1; i < restrictions.length; i++) {
        const distance = restrictions[i][0] - restrictions[i - 1][0];
        const heightWithOneStepIncrement = distance + restrictions[i-1][1];
        restrictions[i][1] = Math.min(restrictions[i][1], heightWithOneStepIncrement)
    }
    
    // If you went incremending from right to left, what is the height you can set for each point,
    // considering its own restriction.
    for(let i = restrictions.length - 2; i >=0; i--) {
        const distance = restrictions[i+1][0] - restrictions[i][0];
        const heightWithOneStepIncrement = distance + restrictions[i+ 1][1];
        restrictions[i][1] = Math.min(restrictions[i][1], heightWithOneStepIncrement)
    }

    let max = 0;
    for(let i = 0; i < restrictions.length - 1; i++) {
        const distance = restrictions[i+1][0] - restrictions[i][0]
        const heightDiff = Math.abs(restrictions[i+1][1] - restrictions[i][1])
        const maxHeight = Math.max(restrictions[i+1][1], restrictions[i][1]);

        const leeway = distance - heightDiff - 1;
        const midHeightBuffer = Math.ceil(leeway / 2)
        max = Math.max(max, maxHeight + midHeightBuffer)
    }
    return max
};