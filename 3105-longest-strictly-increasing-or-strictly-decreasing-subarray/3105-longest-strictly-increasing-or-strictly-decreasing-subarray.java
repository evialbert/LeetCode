class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int result = Integer.MIN_VALUE, start = 0;

        // strictly increasing
        for(int i = 1; i<nums.length; i++)
        {
            // checking if the current index is valid or not to take in our current subarray
            if(nums[i] <= nums[i-1])
            {
                // current element is not valid so we should calculate the result upto the (i-1)th element from start i.e. start to (i-1) which we can get from (i-start)
                result = Math.max(result, i-start);
                start = i;
            }
        }
        result = Math.max(result, nums.length - start);
        start = 0;

        // strictly decresing
        for(int i = 1; i<nums.length; i++)
        {
            if(nums[i] >= nums[i-1])
            {
                result = Math.max(result, i-start);
                start = i;
            }
        }
        result = Math.max(result, nums.length - start);
        return result;
    }
}