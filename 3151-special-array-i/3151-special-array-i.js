/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isArraySpecial = function (nums) {
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] % 2 == nums[i - 1] % 2) {
            return false;
        }
    }
    return true;
};