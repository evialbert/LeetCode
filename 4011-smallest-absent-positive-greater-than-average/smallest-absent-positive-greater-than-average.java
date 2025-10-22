class Solution {
    public int smallestAbsent(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for(int i = 0;i < n;i++) {
            sum += nums[i];
        }
        int avg = sum/n;
        int i = 1;
        while(true){
            int target = 0;
            if(avg < 0){
                target = i;
            }
            else{
               target = avg + i;
            }
            boolean found = isContains(target,nums);
            if(found == false){
                return target;
            }
            i++;
        }
    }
    public boolean isContains(int target,int[] nums){
        
        for (int num : nums) {
            if (num == target) {
                return true;
            }
        }
        return false;
    }
}