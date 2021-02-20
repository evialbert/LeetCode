class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (k < 1 || t < 0) {
            return false;
        }
            
        TreeMap<Long, Integer> tm = new TreeMap<Long, Integer>(); // Counter {key : count}
        
        int size = nums.length;
        for (int i = 0; i < size; ++i) {
            Long n = new Long(nums[i]);
            
            // Remove out of bound key
            if (i - k > 0) {
                Long v = new Long(nums[i-k-1]);
                int c = tm.get(v);
                if (c == 1) {
                    tm.remove(v);
                } else {
                    tm.put(v, c - 1);
                }             
            }
            
            // Compare with closest value in map
            Long lo = tm.floorKey(n);
            if (lo != null && Math.abs(n - lo) <= t) {
                return true;           
            }
            Long hi = tm.ceilingKey(n);
            if (hi != null && Math.abs(n - hi) <= t) {
                return true;
            }
            
            // Put n
            tm.put(n, tm.getOrDefault(n, 0) + 1);
        }
        return false;
    }
}