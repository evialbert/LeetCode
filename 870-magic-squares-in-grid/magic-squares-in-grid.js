/**
 * @param {number[][]} grid
 * @return {number}
 */
var numMagicSquaresInside = function(grid) {
    if (grid.length < 3 || grid[0].length < 3) {
        return 0;
    }

    let sums = 0;

    for (let i = 1; i < grid.length - 1; i++) {
        for (let j = 1; j < grid[i].length - 1; j++) {

            if (grid[i][j] == 5) {
                let a = grid[i-1][j-1];
                let b = grid[i-1][j];
                let c = grid[i-1][j+1];
                let d = grid[i][j-1];
                let e = grid[i][j+1];
                let f = grid[i+1][j-1];
                let g = grid[i+1][j];
                let h = grid[i+1][j+1];

                let mySet = new Set([a, b, c, d, e, f, g, h]);
                let isCheck = true;

                for (let k = 1; k < 9; k++) {
                    if (!mySet.has(k) && k != 5) {
                        isCheck = false;
                        break;
                    }
                }

                if (
                    isCheck &&
                    a + 5 + h == 15 &&
                    c + 5 + f == 15 &&
                    b + 5 + g == 15 &&
                    d + 5 + e == 15 &&
                    a + b + c == 15 &&
                    a + d + f == 15
                ) {
                    sums++;
                }
            }
        }
    }
    return sums;
};