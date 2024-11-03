/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let len = nums.length;
    let xor = len;
    for(let i = 0; i < len; i++) {
        xor = xor ^ i ^ nums[i];
    }
    return xor;
};