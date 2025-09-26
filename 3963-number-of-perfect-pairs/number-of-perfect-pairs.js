/**
 * @param {number[]} nums
 * @return {number}
 */
let perfectPairs = function (nums) {
    const n = nums.length;
    nums.sort((a, b) => Math.abs(a) - Math.abs(b));
    let end = 1, ans = 0;

    for (let start = 0; start < n; start++) {
        while (end < n && Math.abs(nums[end]) <= 2 * Math.abs(nums[start])) end++;
        ans += end - start - 1;
    }

    return ans;
}