class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        if (nums.length % k != 0){
            return false;
        }
        TreeMap<Integer, Integer> freqs = new TreeMap();
        for (int n:nums){
            freqs.put(n, freqs.getOrDefault(n, 0) + 1);
        }
        
        while (freqs.size() > 0){
            int n = freqs.firstKey();
            int count = freqs.get(n);
            while (count > 0){
                int setSize = 1;
                int val = n;
                while (setSize < k){
                    val++;
                    Integer newCount = freqs.get(val);
                    if (newCount == null || newCount == 0){
                        return false;
                    }
                    else{
                        freqs.put(val, newCount - 1);
                        setSize++;
                    }
                }
                count--;
            }
            freqs.remove(n);
        }
        return true;
    }
}