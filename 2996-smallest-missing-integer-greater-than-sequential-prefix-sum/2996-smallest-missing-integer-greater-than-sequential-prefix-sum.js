/**
 * @param {number[]} nums
 * @return {number}
 */
var missingInteger = function(nums) {
    let sum = nums[0];
    const exists = Array(51).fill(false);
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] - nums[i-1] == 1) sum += nums[i];
        else break;
    }
    for (let i of nums) exists[i] = true;
    let check = sum;
    while(check <= 50 && exists[check]) check++;
    return check;
};