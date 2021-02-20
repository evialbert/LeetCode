class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        // Corner case
        if(nums == null || k <= 0) return new int[0];
        
        // Deque of indices of potential max in window (first max, second max, ...)
        Deque<Integer> deque = new ArrayDeque<>();
        
        int[] ans = new int[nums.length + 1 - k];
        int ansIndex = 0;
        
        for(int i = 0; i < nums.length; i++) {
            // Remove the first if the first one is out of window
            if(!deque.isEmpty() && deque.getFirst() <= i - k) {
                deque.removeFirst();
            }
            
            // Remove the last if the last one < current one
            while(!deque.isEmpty() && nums[deque.getLast()] < nums[i]) {
                deque.removeLast();
            }
            
            // The nums in deque should be in the window and in descending order
            deque.addLast(i);
            
            // Fill ans with the first one in deque
            if(i >= k - 1) {
                ans[ansIndex++] = nums[deque.getFirst()];
            }
        }
        
        return ans;
    }
}