/**
 * @param {number[]} nums
 * @param {number} minK
 * @param {number} maxK
 * @return {number}
 */
var countSubarrays = function(nums, minK, maxK) {
    let maxPosition = -1;
    let minPosition = -1;
    let leftBound = -1;
    let answer = 0;
    
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] < minK || nums[i] > maxK) {
            leftBound = i;
        }
        if (nums[i] === minK) minPosition = i;
        if (nums[i] === maxK) maxPosition = i;
        
        let validLength = Math.min(maxPosition, minPosition) - leftBound;
        if (validLength > 0) answer += validLength;
    }
    
    return answer;
};