/**
 * @param {number[]} heights
 * @return {number}
 */
var heightChecker = function (heights) {
    let arr = []
    const doge = [...heights].sort((a, b) => a - b)
    for (let i = 0; i < heights.length; i++) {
        if (doge[i] !== heights[i]) {
            arr.push(doge[i])
        }
    }
    return arr.length
};