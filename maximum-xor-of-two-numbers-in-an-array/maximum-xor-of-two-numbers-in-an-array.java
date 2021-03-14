class Solution {
    public int findMaximumXOR(int[] nums) {
        int max = 0, mask = 0;
        for(int i = 31; i >= 0; i--){
            mask = ~((1 << i) - 1);
            int tmp = max | (1 << i);
            Set<Integer> set = new HashSet<Integer>();
            for(int num: nums){
                int val = num & mask;
                if(set.contains(tmp ^ val))
                    max = Math.max(max, tmp);
                set.add(val);
            }
        }
        return max;
    }
}