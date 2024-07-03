/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumArea = function(grid) {
    
    let minCol = grid[0].length, maxCol = 0, minRow = grid.length, maxRow = 0;

    for(let i = 0; i < grid.length; i++) {

        for(let j = 0; j < grid[0].length; j++) {

            if(grid[i][j] === 0) continue;

            minCol = Math.min(minCol, j);
            maxCol = Math.max(maxCol, j);
            minRow = Math.min(minRow, i);
            maxRow = Math.max(maxRow, i);
        }
    }

    return (maxCol - minCol + 1) * (maxRow - minRow + 1);
};