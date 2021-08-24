class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int prefix[] = new int[nums.length];
        int running_sum = 0;
        for(int i = 0 ; i < nums.length ; i++){
            running_sum = running_sum + nums[i];
            prefix[i] = running_sum % k;
            if(prefix[i] < 0)
                prefix[i] = k - (-1 * prefix[i]);
        }
        
        HashMap<Integer,Integer> map = new HashMap<>();
        
        map.put(0,1);
        int res = 0;
        for(int i = 0 ; i < prefix.length ; i++){
            res += map.getOrDefault(prefix[i],0);
            map.put(prefix[i],map.getOrDefault(prefix[i],0)+1);
        }
        return res;
    }
}