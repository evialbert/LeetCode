/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var missingMultiple = function (nums, k) {
    let set = new Set(nums);
    let mulK = 0;

    let i = 0;
    while (i <= nums.length) {
        mulK += k;
        if (!set.has(mulK)) {
            return mulK;
        }
        i++;
    }
    return mulK;
};