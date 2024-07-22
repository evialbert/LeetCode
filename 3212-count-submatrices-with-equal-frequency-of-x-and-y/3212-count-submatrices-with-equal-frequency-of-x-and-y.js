/**
 * @param {character[][]} grid
 * @return {number}
 */
var numberOfSubmatrices = function (grid) {
    const rows = grid.length;
    const cols = grid[0].length;

    const cumSum = Array.from({ length: rows }, () => Array(cols).fill(0));
    const firstX = [rows, cols];

    let submatrixCount = 0;

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (grid[i][j] === 'X') {
                firstX[0] = Math.min(firstX[0], i);
                firstX[1] = Math.min(firstX[1], j);
            }

            const top = i - 1 < 0 ? 0 : cumSum[i - 1][j];
            const left = j - 1 < 0 ? 0 : cumSum[i][j - 1];
            const topLeft = (i - 1 < 0 || j - 1 < 0) ? 0 : cumSum[i - 1][j - 1];
            cumSum[i][j] = (grid[i][j] === 'X' ? 1 : grid[i][j] === 'Y' ? -1 : 0) + top + left - topLeft;

            if (cumSum[i][j] === 0 && i >= firstX[0] && j >= firstX[1]) {
                submatrixCount++;
            }
        }
    }

    return submatrixCount;
};