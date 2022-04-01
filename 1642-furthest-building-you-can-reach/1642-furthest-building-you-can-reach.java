class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        Queue<Integer> minHeap = new PriorityQueue<>();
        for(int i = 0; i < heights.length - 1; i++){
            int jumpLength = heights[i+1] - heights[i];
            if(jumpLength <= 0){ // next building is lower than current
                continue;
            }
            minHeap.offer(jumpLength);
            if(ladders > 0){ // if ladders are remaining
                ladders--;
            }else{ // we are out of ladders so we have to remove the lowest jump and replace with bricks; all the ladders are consumed at this point
                int lowestHeight = minHeap.poll();
                bricks-=lowestHeight; // using bricks for lowest jump
            }
            
            if(bricks < 0){ //if we used up all ladders and are falling short of bricks for the next step, we can't go further
                return i;
            }
        }
        
        return heights.length - 1; // when we could reach the last building
    }
}