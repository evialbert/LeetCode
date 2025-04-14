/**
 * @param {number[]} nums
 * @return {number}
 */
var triangleNumber = function(nums) {
    const n = nums.length;
    
    nums.sort((a, b) => a - b);
    
    let count = 0;
    
    for (let i = 2; i < n; i++) {
        const currNum = nums[i];
        
        let left = 0;
        let right = i - 1;
        
        while (left < right) {
            const leftNum = nums[left];
            const rightNum = nums[right];
            
            if (leftNum + rightNum > currNum) {
                count += right - left;
                right--;
            } else {
                left++;
            }
        }
    }
    
    return count;
};