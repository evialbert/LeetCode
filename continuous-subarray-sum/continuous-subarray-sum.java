class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int sum = 0;
        for(int i=0;i<nums.length;i++) {
            sum += nums[i];
            sum = k!=0? sum%k: sum;
            if(map.containsKey(sum)) {
                int lastIx = map.get(sum);
                if(i - lastIx > 1) return true; // 2 elemeents
            } else
                map.put(sum, i);
        }
        return false;
    }
}