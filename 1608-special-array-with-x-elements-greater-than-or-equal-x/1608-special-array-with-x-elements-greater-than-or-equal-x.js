/**
 * @param {number[]} nums
 * @return {number}
 */
var specialArray = function(nums) {
    nums.sort((a,b) => a-b);
    let n = nums.length;
    let i = 0, j = n-1;
    
    while (i < j) {
        let mid = Math.floor((i+j)/2);
        
        if (nums[mid] < n-mid) {
            i = mid+1;
        }
        else {
            j = mid;
        }
    }
    
    return ((i == 0 && n <= nums[i]) || (nums[i-1] < n-i && n-i <= nums[i])) ? n-i : -1;
};