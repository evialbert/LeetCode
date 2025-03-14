/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findPairs = function(nums, k) {
    const set = new Set();
    const ans = new Set();
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        const val1 = nums[i] + k;
        const val2 = nums[i] - k;
        
        if (set.has(val1)) {
            ans.add(`${nums[i]}#${val1}`);
        }
        
        if (set.has(val2)) {
            ans.add(`${val2}#${nums[i]}`);
        }

        set.add(nums[i]);
    }

    return ans.size;
};