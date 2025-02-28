/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var sumOfGoodNumbers = function(nums, k) {
    
    let sum = 0;

    for(let i = 0; i < nums.length; i++) {

        const left = nums[i - k] || 0, right = nums[i + k] || 0;
        sum += nums[i] > left && nums[i] > right ? nums[i] : 0;
    }

    return sum;
};