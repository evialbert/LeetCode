class Solution {
    public int addRungs(int[] rungs, int dist) {      
        int count = 0;
        
        if(rungs[0] > dist)
            count += (rungs[0]-1)/dist;
        
        for(int i=1; i<rungs.length; i++){
            if(rungs[i] - rungs[i-1] <= dist)
                continue;
            
            else{
                int diff = rungs[i] - rungs[i-1];
                
                count += (diff-1)/dist;
            }
        }
        
        return count;
    }
}