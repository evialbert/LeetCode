/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canSortArray = function(nums) {
    nums.sort((a, b) => {
        let aBinStr = a.toString(2)
        let bBinStr = b.toString(2)
        let aBinStr1Num = 0
        for (let i = 0; i < aBinStr.length; ++ i) {
            if (aBinStr[i] == '1') {
                aBinStr1Num ++
            }
        }
        for (let i = 0; i < bBinStr.length; ++ i) {
            if (bBinStr[i] == '1') {
                aBinStr1Num --
            }
        }
        if (aBinStr1Num == 0) {
            return a - b
        } else {
            return 0
        }
    })
    for (let i = 1; i < nums.length; ++ i) {
        if (nums[i] < nums[i - 1]) {
            return false
        }
    }
    return true
};