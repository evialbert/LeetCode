/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    // Function to swap elements in the array
    const swap = (arr, i, j) => {
        [arr[i], arr[j]] = [arr[j], arr[i]];
    };
    
    const n = nums.length;
    
    // Place each positive integer i at index i-1 if possible
    for (let i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[i] !== nums[nums[i] - 1]) {
            swap(nums, i, nums[i] - 1);
        }
    }
    
    // Find the first missing positive integer
    for (let i = 0; i < n; i++) {
        if (nums[i] !== i + 1) {
            return i + 1;
        }
    }
    
    // If all positive integers from 1 to n are present, return n + 1
    return n + 1;
};