/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    let flips = 0;

    for (let i = 0; i < nums.length; ++i) {
        if (flips % 2 === 1) {
            if (nums[i] === 1) ++flips;
        } else if (nums[i] === 0) {
            ++flips;
        }
    }

    return flips;
};