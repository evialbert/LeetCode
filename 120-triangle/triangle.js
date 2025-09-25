/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
    return triangle.reverse().reduce((acc, row) => row.map((val, i) => val + Math.min(acc[i], acc[i + 1])))[0];
};