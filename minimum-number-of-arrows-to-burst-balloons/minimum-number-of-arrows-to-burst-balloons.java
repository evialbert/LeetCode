class Solution {
   public int findMinArrowShots(int[][] points) {
    if(points.length == 0) return 0;
    sort(points); //sort by starting point
   //use left and right to record the current overlapping area
    int left = points[0][0]; 
    int right = points[0][1];
    int res = points.length; 
    for (int i = 1; i < points.length; i++) {
        if (points[i][0]<=right) { //If overlap occurs
             res--;  //an overlapping means one less arrow    
          left = Math.max(left, points[i][0]); //update the left and right border
          right = Math.min(right, points[i][1]);
 //for example, the first ballons is [1,5], the second ballon is [3,7]       
//1 -----     [1,5]
//2   -----   [3,7]
// we need to find the overlapping area, so we need to get the max value of their left border(3) and the minimum value of their right border(5).
//So the overlapping area is [3,5]                 
        
        }
        else  //no overlapping
        {
            left = points[i][0]; //move the area to the next location
            right = points[i][1];
        }
         
    }
    return res;

}
 void sort(int[][] nums) {
    Arrays.sort(nums, new Comparator<int[]>() {
        @Override
        public int compare(int[] a, int[] b) {
            if(a[0]<b[0])
            return -1;
        if(a[0]>b[0])
            return 1;
        return a[0]-b[0];
        }
    });
}

}