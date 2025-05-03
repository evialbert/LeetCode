/**
 * @param {number[]} tops
 * @param {number[]} bottoms
 * @return {number}
 */
var minDominoRotations = function(tops, bottoms) {
    const n = tops.length;
    
    // Helper function to count rotations needed to make all values equal to target
    const check = (target) => {
        let rotationsTop = 0;
        let rotationsBottom = 0;
        for (let i = 0; i < n; i++) {
            if (tops[i] !== target && bottoms[i] !== target) {
                return -1;
            } else if (tops[i] !== target) {
                rotationsTop++;
            } else if (bottoms[i] !== target) {
                rotationsBottom++;
            }
        }
        return Math.min(rotationsTop, rotationsBottom);
    }

    // Try making all values equal to tops[0] or bottoms[0]
    let rotations = check(tops[0]);
    
    // If tops[0] and bottoms[0] are the same, no need to check again
    if (rotations !== -1 || tops[0] === bottoms[0]) {
        return rotations;
    } else {
        return check(bottoms[0]);
    }
};