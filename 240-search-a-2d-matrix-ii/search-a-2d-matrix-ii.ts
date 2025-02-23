function searchMatrix(matrix: number[][], target: number): boolean {
    let row = 0;
    let col = matrix[0].length - 1;

    while (col >= 0 && row < matrix.length) {
        if (matrix[row][col] === target) return true;
        
        if (matrix[row][col] > target) {
            col--;
            continue;
        }

        row++;
    }

    return false;
};