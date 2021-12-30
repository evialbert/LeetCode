class Solution {
    public int longestSubarray(int[] nums, int limit) {
        TreeMap<Integer, Integer> window = new TreeMap<>();
        int l = 0;
        int r = 0;
        int maxLength = 0;
        while (r < nums.length) {
            addToWindow(window, nums[r++]);
            while (window.lastKey() - window.firstKey() > limit) {
                removeFromWindow(window, nums[l++]);
            }
            maxLength = Math.max(r - l, maxLength);
        }
        
        return maxLength;
    }
    
    private void removeFromWindow(Map<Integer, Integer> window, int value) {
        if (window.containsKey(value)) {
            int occurencies = window.get(value);
            if (occurencies == 1) {
                window.remove(value);
            } else {
                window.put(value, occurencies - 1);
            }
        }
    }
    
    private void addToWindow(Map<Integer, Integer> window, int value) {
        window.put(value, window.getOrDefault(value, 0) + 1);
    }
}