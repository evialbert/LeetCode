class Solution {
    public long countBadPairs(int[] nums) {
        int n = nums.length ; 
        for( int i=0 ; i<n ; ++i ){
            nums[i] -= i; 
        }
        Arrays.sort(nums) ; 
        long rs = 0L ; 
        for( int i=0 ; i<n ; ++i ){
            int count = 1 ; 
            while( i+1<n && nums[i+1] == nums[i] ){
                i++ ; 
                count++ ; 
            }
            rs += count*(n-count) ;
        }

        return rs >> 1 ;  
    }
}