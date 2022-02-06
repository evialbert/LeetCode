class Solution {
    public int findMaxValueOfEquation(int[][] points, int k) {

        Deque<int[]>queue = new ArrayDeque();
        int res = Integer.MIN_VALUE;
        for(int[]point:points){

            while(!queue.isEmpty() && point[0]-queue.peekFirst()[0]>k){
                queue.pollFirst();
            }
            if(!queue.isEmpty()){
                res = Math.max(res,point[0]+point[1]+queue.peekFirst()[1]);
            }
            while(!queue.isEmpty() && point[1]-point[0]>queue.peekLast()[1]){
                queue.pollLast();
            }
            queue.offerLast(new int[]{point[0],point[1]-point[0]});
        }
        return res;
    }
}