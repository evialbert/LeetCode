/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number[][]} edges
 * @return {number}
 */
var maximumValueSum = function (nums, k, edges) {
    let count = 0;
    let sum = 0;
    let minDiff = Infinity;
    for (let num of nums) {
        let xorNum = (num ^ k);
        if (xorNum > num) {
            count++;
        }
        sum += Math.max(xorNum, num);
        minDiff = Math.min(Math.abs(xorNum - num), minDiff);
    }

    if (count % 2 === 1) sum -= minDiff;

    return sum;
};