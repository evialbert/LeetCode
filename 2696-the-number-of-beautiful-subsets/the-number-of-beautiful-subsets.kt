class Solution {
    fun beautifulSubsets(nums: IntArray, k: Int): Int {
        fun f(k: Int, i: Int, mask: Int): Int = 
            if (i==nums.size) if (mask>0) 1 else 0
            else f(k, i+1, mask) +
                    if ((0..<i).all { (1.shl(it)).and(mask) == 0 || (nums[it]-nums[i]).absoluteValue != k }) f(k, i+1, mask+1.shl(i)) else 0

        return f(k, 0, 0)
    }
}