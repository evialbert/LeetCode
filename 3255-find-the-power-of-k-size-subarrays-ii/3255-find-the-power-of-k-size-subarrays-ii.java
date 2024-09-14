class Solution {
    public int[] resultsArray(int[] nums, int k) {
        if(nums.length == 0 || nums.length == 1 || k == 1){
            return nums;
        }
        HashSet<Integer> set = new HashSet<>();
        int st = 0; int end = 0; int n = nums.length;
        while(true){
            while(end+1 < n && nums[end] + 1 == nums[end+1]){
                end++;
                if(end-st >= k-1) set.add(end);
            }
            if(end < n){
                end++;
                st = end;
            }else{
                break;
            }
        }
        int[] ans = new int[n-k+1];
        for(int j = k-1; j < n; j++){
            if(set.contains(j)){
                ans[j-k+1] = nums[j];
            }else{
                ans[j-k+1] = -1;
            }
        }
        return ans;
    }
}