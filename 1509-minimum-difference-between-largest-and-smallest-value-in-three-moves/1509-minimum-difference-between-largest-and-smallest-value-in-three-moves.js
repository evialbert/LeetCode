/**
 * @param {number[]} nums
 * @return {number}
 */
var minDifference = function(nums) {
    nums.sort((a, b) => a - b);
    
    if (nums.length <= 4) {
        return 0;
    }
    
    let res = Infinity;
    
    res = Math.min(res, nums[nums.length - 4] - nums[0])
    res = Math.min(res, nums[nums.length - 3] - nums[1])
    res = Math.min(res, nums[nums.length - 2] - nums[2])
    res = Math.min(res, nums[nums.length - 1] - nums[3])
    
    return res;
    
    
};