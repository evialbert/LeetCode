class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int ans = 0;
        int i=0,j=0;
        Map<Integer,Integer> map = new HashMap();
        while(j<nums.length){
            map.put(nums[j],map.getOrDefault(nums[j],0)+1);
            if(map.get(nums[j])>k){
                while(map.get(nums[j])>k){
                    int val = map.get(nums[i]);
                    if(val-1==0){
                        map.remove(nums[i]);
                    }else{
                        map.put(nums[i],val-1);
                    }
                    i++;
                }
            }
            ans = Math.max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
}