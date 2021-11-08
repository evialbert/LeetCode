class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals,(a,b)->a[0]-b[0]); //sort by start point
        int[] bound = intervals[0]; //this tells us the current bound
        int covered=0;
        for(int i=1;i<intervals.length;i++){
            //if this interval is within the bounds , it is covered .
            if(intervals[i][0]>=bound[0] && intervals[i][1]<=bound[1]) covered++;
            else{
            //if this interval is not within the bounds ,it will be made as the new bound....
            //Now we need to check whether the previous bound is within the new bound.
                int[] prevbound=bound;
                bound=intervals[i];
                if(prevbound[0]>=bound[0] && prevbound[1]<=bound[1]) covered++;
            }
        }
        //left intervals = total-covered intervals
        return intervals.length-covered;
    }
}