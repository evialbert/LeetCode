class Solution {
    public int minIncrementForUnique(int[] nums) {
        if(nums == null || nums.length == 0)
            return 0;
        Arrays.sort(nums);
        int moves = 0;
        Integer prev = null;

        for (int i = 0; i < nums.length; i++){
            int curr = nums[i];
            if(prev != null && curr <= prev.intValue()){
                moves += (prev - curr +1);
                prev = curr + (prev - curr +1);
            }else{
                prev = curr;
            }
        }
        return moves;
    }
}