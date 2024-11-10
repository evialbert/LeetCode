/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minimumSubarrayLength = function(nums, k) {
     let ans = Infinity;
    let ors = 0;
    let count = new Array(30).fill(0);
    let left = 0;
    
    for (let right = 0; right < nums.length; right++) {
        ors = updateOr(ors, nums[right], count);
        
        while (ors >= k && left <= right) {
            ans = Math.min(ans, right - left + 1);
            ors = undoOr(ors, nums[left], count);
            left++;
        }
    }
    
    return ans === Infinity ? -1 : ans;
}

function updateOr(ors, num, count) {
    for (let i = 0; i < 30; i++) {
        if ((num >> i) & 1 && ++count[i] === 1) {
            ors |= 1 << i;
        }
    }
    return ors;
}

function undoOr(ors, num, count) {
    for (let i = 0; i < 30; i++) {
        if ((num >> i) & 1 && --count[i] === 0) {
            ors ^= 1 << i;
        }
    }
    return ors; 
};