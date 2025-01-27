/**
 * @param {number[][]} grid1
 * @param {number[][]} grid2
 * @return {number}
 */
var countSubIslands = function(grid1, grid2) {
    const rows = grid2.length;
    const cols = grid2[0].length;
    let subIslandsCount = 0;

    const dfs = (i, j) => {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid2[i][j] === 0) {
            return true;
        }

        grid2[i][j] = 0;

        let isSubIsland = grid1[i][j] === 1;

        isSubIsland &= dfs(i - 1, j);
        isSubIsland &= dfs(i + 1, j);
        isSubIsland &= dfs(i, j - 1);
        isSubIsland &= dfs(i, j + 1);

        return isSubIsland;
    };

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (grid2[i][j] === 1 && dfs(i, j)) {
                subIslandsCount++;
            }
        }
    }

    return subIslandsCount;
};