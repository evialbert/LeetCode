class Solution {
    public int scoreDifference(int[] nums) {
        int first = 0;
        int second = 0;
        int active = 0; 
        for (int i = 0; i < nums.length; i++) {

            if (nums[i] % 2 == 1) {
                active ^= 1;  
            }

            if (i % 6 == 5) {
                active ^= 1;
            }

            if (active == 0) {
                first += nums[i];
            } else {
                second += nums[i];
            }
        }

        return first - second;
    }
}