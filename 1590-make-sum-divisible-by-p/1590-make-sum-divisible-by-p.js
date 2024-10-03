/**
 * @param {number[]} nums
 * @param {number} p
 * @return {number}
 */
var minSubarray = function(nums, p) {
    const sum = nums.reduce((a, b) => a + b, 0)
    const totalRemainder = sum % p
    if (totalRemainder == 0) return 0

    let map = new Map(),
        curRemainder = 0,
        res = nums.length
    map.set(0, -1)
    for (let i = 0; i < nums.length; i++) {
        curRemainder = (curRemainder + nums[i]) % p
        const targetRemainder = (curRemainder - totalRemainder + p) % p
        if (map.has(targetRemainder)) {
            res = Math.min(res, i - map.get(targetRemainder))
        }
        map.set(curRemainder, i)

    }
    return res == nums.length ? -1 : res
};