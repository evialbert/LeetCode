/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function(nums) {
    let counter = 0;
    for(let i=0;i<=nums.length-3;i++){
        if(nums[i] === 0){
            nums[i] = nums[i] === 0 ? 1 : 0;
            nums[i+1] = nums[i+1] === 0 ? 1 : 0;
            nums[i+2] = nums[i+2] === 0 ? 1 : 0; 
            counter++;
        }
    }
    if(nums[nums.length-3] === 0 || nums[nums.length-2] === 0 || nums[nums.length-1] === 0)
        return -1;
    return counter
};