/**
 * @param {number[]} nums
 * @return {boolean}
 */
var primeSubOperation = function(nums) {
    const pick = (num, r) => {
        let p = Math.max(2, num - r + 1), d
        if (p >= num)
            return 0
        if (p == 2)
            return 2
        if (p % 2 == 0)
            p += 1
        while (p < num) {
            d = 3
            while (p % d) {
                if (p < d * d)
                    return p
                d += 2
            }
            p += 2
        }
        return 0
    }
    let d = nums.at(-1)
    for (let i = nums.length-2; i >= 0; i--) {
        if (nums[i] >= d) {
            p = pick(nums[i], d)
            if (p == 0)
                return false
            d = nums[i] - p
        } else 
            d = nums[i]
    }
    return true
};