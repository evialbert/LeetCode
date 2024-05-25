/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {boolean[]}
 */
var isArraySpecial = function(nums, queries) {  

    const intervals = [0];

    for(let i = 1; i < nums.length; i++) {

        intervals.push(intervals[i - 1] + (nums[i - 1] % 2 === nums[i] % 2 ? 1 : 0));
    }

    const ans = [];

    for(const [start, end] of queries) {
        ans.push(intervals[start] === intervals[end]);
    }
    
    return ans;
};