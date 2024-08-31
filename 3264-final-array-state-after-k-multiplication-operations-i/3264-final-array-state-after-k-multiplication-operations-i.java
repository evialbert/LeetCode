class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        PriorityQueue<Integer> pq=new PriorityQueue<Integer>();
        for(int i=0;i<nums.length;i++){
            pq.add(nums[i]);
        }
        while(k>0){
        for(int i=0;i<nums.length;i++){
            if(nums[i]==pq.peek()){
                nums[i]=nums[i]*multiplier;
                k--;
                pq.poll();
                pq.add(nums[i]);
                break;
            }
        }
    }
    return nums;
    }
}