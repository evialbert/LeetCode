/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minOperations = function(nums, k) {
    // Count unique values > k
    let uniqueValues = new Set();
    for (let num of nums) {
        if (num < k) {
            return -1;
        }
        if (num > k) {
            uniqueValues.add(num);
        }
    }
    
    // Each unique value needs one operation
    return uniqueValues.size;
};