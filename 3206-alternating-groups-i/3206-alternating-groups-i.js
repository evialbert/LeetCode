/**
 * @param {number[]} colors
 * @return {number}
 */
var numberOfAlternatingGroups = function(colors) {
      let n = colors.length;
    let count = 0;

    for (let i = 0; i < n; i++) {
    
        let current = colors[i];
        let next = colors[(i + 1) % n];
        let nextNext = colors[(i + 2) % n];
        if (current !== next && next !== nextNext && current === nextNext) {
            count++;
        }
    }

    return count;
};