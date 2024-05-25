/**
 * @param {number[]} nums
 * @return {number}
 */
var sumDigitDifferences = function (nums) {
    const x = nums.length - 1
    const n = nums[0].toString().length
    const memo = new Array(n).fill(0).map(() => new Array())
    for (let i = 0; i <= x; i++) {
        for (let j = n - 1; j >= 0; j--) {
            memo[j].push(nums[i] % 10)
            nums[i] = Math.floor(nums[i] / 10)
        }
    }
    let ans = 0
    for (let i = 0; i < n; i++) {
        memo[i].sort((a, b) => a - b)
        let last = 0, l = 0
        for (let j = 0; j < 10; j++) {
            let r = x, temp = x + 1
            while (l <= r) {
                const mid = Math.floor(l + (r - l) / 2)
                if (memo[i][mid] >= j + 1) {
                    r = mid - 1
                } else if (memo[i][mid] < j + 1) {
                    l = mid + 1
                }
            }
            temp -= (l - last)
            ans += (l - last) * temp
            last = l
        }
    }
    return ans / 2
};