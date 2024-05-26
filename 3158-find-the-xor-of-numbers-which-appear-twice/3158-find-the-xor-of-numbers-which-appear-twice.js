/**
 * @param {number[]} nums
 * @return {number}
 */
var duplicateNumbersXOR = function(nums) {
    let ans = 0

    for (let i = 0; i < nums.length - 1; i++) {
        if (nums.indexOf(nums[i], i + 1) != -1) {
            ans = ans ^ nums[i]
        }
    }

    return ans
};