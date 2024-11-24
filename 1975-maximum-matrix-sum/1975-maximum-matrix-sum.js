/**
 * @param {number[][]} matrix
 * @return {number}
 */
var maxMatrixSum = function(matrix) {
    let result = 0;
    let negativeCount = 0;
    let minNum = Infinity;
    for(let r=0; r<matrix.length; r++) {
        for(let c=0; c<matrix[0].length; c++) {
            result += Math.abs(matrix[r][c]);
            minNum = Math.min(minNum, Math.abs(matrix[r][c]));
            if(matrix[r][c] < 0) negativeCount++;
        }
    }

    if(negativeCount & 1) {
        result -= (2 * minNum);
    }

    return result;
};