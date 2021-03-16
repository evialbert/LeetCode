class Solution {
    private int getNext(int[] nums, int idx) {
        int n = nums.length;
        return ((nums[idx] + idx) % n + n) % n;
    }
    
    public boolean circularArrayLoop(int[] nums) {
        if(nums == null || nums.length == 0) {
            return false;
        }
        int n = nums.length;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                continue; // no need to visit OR has visited
            }
            
            int slow = i, fast = i, val = 0;
            
            while(nums[fast] * nums[i] > 0 && nums[getNext(nums, fast)] * nums[i] > 0) {
                
                slow = getNext(nums, slow);
                fast = getNext(nums, getNext(nums, fast));
                
                // ensure the direction remains same
                if (slow == fast) {
                    if (slow == getNext(nums, slow)) {
                        // check for loop that only contains one element
                        break;
                    }
                    // valid answer
                    return true;
                }
            }
            
            // loop not found, set all element along the way to 0
            // let them avoid being visited again
            slow = i;
            val = nums[i];
            while(nums[slow] * val > 0) {
                int next = getNext(nums, slow);
                nums[slow] = 0;
                slow = next;
            }
        }
        
        return false;
    }
}