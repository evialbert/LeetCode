class Solution {
    fun findDifferentBinaryString(nums: Array<String>): String {
        val ans = StringBuilder()
        for (i in nums.indices) {
            if (nums[i][i] == '0') {
                ans.append('1')
            } else {
                ans.append('0')
            }
        }
        return ans.toString()
    }
}