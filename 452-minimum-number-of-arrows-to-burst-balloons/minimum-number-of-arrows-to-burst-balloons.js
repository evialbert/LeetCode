/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function (points) {

    let sorted = points.sort((a, b) => a[0] - b[0]);
    let output = [sorted[0]];
    for (let i = 1; i < sorted.length; i++) {
        if (sorted[i][0] <= output[output.length - 1][1]) { //overlapped
            output[output.length - 1][1] = Math.min(sorted[i][1], output[output.length - 1][1])
        } else {
            output.push(sorted[i]);
        }
    }
    return output.length;

};