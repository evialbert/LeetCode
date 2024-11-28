/**
 * @param {number[]} nums
 * @param {number} l
 * @param {number} r
 * @return {number}
 */
var minimumSumSubarray = function (nums, l, r) {
    if (nums.length < l) return -1;
    let sum = 0;
    let res = Number.MAX_VALUE;
    let n = nums.length;
    for (let i = 0; i < n; i++) {
        let m = Math.min(n, i + r);
        sum = 0;
        for (let j = i; j < m; j++) {
            sum += nums[j];
            if (j - i + 1 >= l && j - i + 1 <= r && sum > 0) {
                //console.log(sum)
                res = Math.min(res, sum);
            }
        }
    }
    if (res === Number.MAX_VALUE) res = -1;
    return res;
};