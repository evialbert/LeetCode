/**
 * @param {number[][]} grid
 * @return {number}
 */
var matrixScore = function(grid) {
   let m = grid.length;
   let n = grid[0].length;
   let res = Math.pow(2, n - 1) * m;

   for(let j = 1; j < n; j++){
       let curr = 0;

    for(let i = 0; i < m; i++){
        curr += grid[i][0] === grid[i][j] ? 1 : 0;
    }
    res += Math.max(curr, m - curr) * Math.pow(2, n - 1 - j);
   } 
   return res;
};