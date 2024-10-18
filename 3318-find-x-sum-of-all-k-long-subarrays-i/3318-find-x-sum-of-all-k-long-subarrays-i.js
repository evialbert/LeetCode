/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var findXSum = function (nums, k, x) {
    let res = [];
    for (let i = 0; i < nums.length - k + 1; i++) {
        let map = new Map();
        for (let j = i; j < i + k; j++) {
            map.set(nums[j], (map.get(nums[j]) || 0) + 1);
        }
        let arr = [...map].sort((a, b) => (b[1] - a[1]) || (b[0] - a[0]));
        let a = 0;
        let len = Math.min(x, arr.length);
        for (let n = 0; n < len; n++) {
            a += arr[n][0] * arr[n][1];
        }
        res.push(a);
    }
    return res;
};