class Solution {
    public int triangularSum(int[] nums) {
        if(nums.length==1)return nums[0];
        Queue<Integer> queue=new LinkedList<>();
        for(int num:nums){
            queue.offer(num);
        }
        while(queue.size()!=2){
            int lastpoll=queue.poll();
            int queuesize=queue.size();
            for(int i=0;i<queuesize;i++){
                int cpoll=queue.poll();
                queue.offer((cpoll+lastpoll)%10);
                lastpoll=cpoll;
            }
        }
        return (queue.poll()+queue.poll())%10;
    }
}