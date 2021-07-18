class Solution {
  public int minRefuelStops(int target, int startFuel, int[][] stations) {
    
    //we will use max heap
    PriorityQueue<Integer> heap=new PriorityQueue<>(Collections.reverseOrder());
    int count=0;
    //nlogn complexity
    //start traversing
    for(int i=0;i<stations.length;i++){
        int s=stations[i][0];
        int r=stations[i][1];
        
        //check if we could have reached the point without refilling
        if(startFuel>=s){
            if(s==target){
                return count;
            }
            heap.add(r);
            continue;
        }
        
        //else
        //we take highest refill value that we left in the past until we can reach
        while(startFuel<s){
            if(heap.isEmpty()){
                return -1;
            }
            int rm=heap.remove();
            startFuel+=rm;
            count++;
        }
        heap.add(r);
        
        //target check again
        if(s==target){
            return count;
        }
    }
    
    
   //if target does not lie in stations range it is farther than that
    
    while(startFuel<target){
        if(heap.isEmpty()){
            return -1;
        }
        int rm=heap.remove();
        startFuel+=rm;
        count++;
    }
    
    return count;
}
}