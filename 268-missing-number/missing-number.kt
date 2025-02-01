class Solution {
    fun missingNumber(nums: IntArray): Int {
        var sortedNums = nums.sorted()
        for (n in sortedNums.indices) {
            if (n != sortedNums[n]) return n
        }
        return nums.size
    }
}