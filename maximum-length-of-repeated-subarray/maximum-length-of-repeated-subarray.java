class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        
        int al =nums1.length;
        int bl =nums2.length;
        
         int[][] T = new int[al+1][al+1];

        int max = 0;
        for(int i=0; i < al; i++){
            
            for(int j=0; j < bl; j++){
                
                if(nums1[i] == nums2[j]){
                    
                    T[i+1][j+1] = T[i][j] +1;
                    
                    max = Math.max(max,T[i+1][j+1]);
                }
            }
        }
        return max;
    }
}