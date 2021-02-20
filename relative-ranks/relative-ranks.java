class Solution {
    public String[] findRelativeRanks(int[] nums) {
        int[] c_nums = nums.clone();
        Arrays.sort(c_nums);
        Map<Integer, Integer> ranks = new HashMap<>();
        for(int i = c_nums.length - 1; i >= 0; i--){
            ranks.put(c_nums[i], c_nums.length-i);
        }
        String[] medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        String[] ans = new String[nums.length];
        for(int i = 0; i < nums.length; i++){
            int num = nums[i];
            int r = ranks.get(num);
            if(r<=3){
                ans[i] = medals[r-1];
            }else{
                ans[i] = r+"";
            }
        }
        return ans;
    }
}