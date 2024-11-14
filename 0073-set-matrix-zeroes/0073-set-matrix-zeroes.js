/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    const m = matrix.length;
    const n = matrix[0].length;

    let rows = new Array(m).fill(1);
    let columns = new Array(n).fill(1);

    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(matrix[i][j] === 0){
                rows[i] = 0;
                columns[j] = 0;
            }
        }
    }

    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(rows[i] === 0 ||columns[j] === 0){
                matrix[i][j] = 0;
            }
        }
    }
};