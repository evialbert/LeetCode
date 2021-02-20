class Solution {
    public int majorityElement(int[] nums) {
        int count = 1, current = nums[0];
        for(int i = 1; i < nums.length; i++) {
            if(count == 0) {
                count++;
                current = nums[i];
            }
            else if(current==nums[i])
                count++;
            else
                count--;
        }
        return current;
    }
}