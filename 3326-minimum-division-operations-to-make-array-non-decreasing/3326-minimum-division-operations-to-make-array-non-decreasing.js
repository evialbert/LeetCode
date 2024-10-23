/**
 * @param {number[]} nums
 * @return {number}
 */
function minOperations(nums) {
    function init() {
        next = new Uint16Array(1000001);
        for (let n = 2; n < 1000; n++) {
            if (next[n]) continue;
            for (let nn = n * n; nn < 1000001; nn += n) {
                next[nn] ||= n;
            }
        }
    }
    if (this.next === undefined) init();
    let ops = 0, i = nums.length - 1;
    while (~--i) {
        if (nums[i] <= nums[i + 1]) continue;
        ops++, nums[i] = next[nums[i]] || nums[i];
        if (nums[i] > nums[i + 1]) return -1;
    }
    return ops;
}