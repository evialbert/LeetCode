/**
 Do not return anything, modify matrix in-place instead.
 */
function setZeroes(matrix: number[][]): void {
    var array = [];
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            if (matrix[i][j] === 0) {
                array.push([i, j]);
            }
        }
    }

    for (let i = 0; i < array.length; i++) {
        var row = array[i][0];
        var col = array[i][1];

        for (let i = 0; i < matrix.length; i++) {
            matrix[i][col] = 0;
        }

        for (let j = 0; j < matrix[row].length; j++) {
            matrix[row][j] = 0;
        }
    }
};