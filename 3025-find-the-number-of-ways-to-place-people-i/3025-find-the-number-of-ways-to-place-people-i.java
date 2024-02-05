class Solution {
    public int numberOfPairs(int[][] points) {
        
        Arrays.sort(points, Comparator.comparingInt((int[] arr) -> arr[0]).thenComparing(Comparator.comparingInt((int[] arr) -> arr[1]).reversed()));
        
        int ans = 0;
        for(int i=0;i<points.length-1;i++){
            // max y smaller than xi
            int max_y = Integer.MIN_VALUE;
            for(int j=i+1;j<points.length;j++){
                int xi = points[i][0];
                int yi = points[i][1];
                
                int xj = points[j][0];
                int yj = points[j][1];
                
                if(yi >= yj && yj > max_y){
                    ans++;
                    max_y = yj;
                }
            }
        }
        return ans;
        
        
    }
}