/**
 * @param {number[]} nums
 * @return {number}
 */
var longestMonotonicSubarray = function(nums) {

    let inc = 1, dec = 1, max = 1;

    for(let i = 1; i < nums.length; i++) {

        if(nums[i] === nums[i - 1]) {
            inc = dec =1;
            continue;
        }

        if(nums[i] > nums[i - 1]) {
            inc++;
            dec = 1;
        } else {
            inc = 1;
            dec++;
        }

        max = Math.max(max, inc, dec);
    }
    
    return max;
};