class Solution {
    public int findMaxK(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int maxNum = -1;

        for(int num : nums){
            if(set.contains(-num))
                maxNum = Math.max(maxNum, Math.abs(num));
                
            set.add(num);
        }

        return maxNum;
    }
}