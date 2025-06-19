/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[][]}
 */
var divideArray = function (nums, k) {
    /**
        [1,1,3,3,4,5,7,8,9]
        [2,2,2,2,4,5]
     */
    nums.sort((a, b) => a - b);
    let res = [];
    let i = 2;
    while (i < nums.length) {
        if (nums[i] - nums[i - 2] <= k) {
            res.push([nums[i - 2], nums[i - 1], nums[i]]);
            i += 3;
        } else {
            return [];
        }
    }
    return res;

};