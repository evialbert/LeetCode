class Solution {
    public int countElements(int[] nums) {
        int max = -100001, min = 100001, n = nums.length, max_duplicate = 0, min_duplicate = 0;
        if( n <= 1) return 0; 
        for(int i:nums){
            if( i == max ) max_duplicate++;
            if( i == min ) min_duplicate++;
            if( i > max) {
                max = i;
                max_duplicate = 0;
            }
            if(i < min){
                min = i;
                min_duplicate = 0;
            }
        }
        int res = (n - 2) - max_duplicate - min_duplicate; // If no duplicates are present, answer will be length of nums - 2
        return res < 0 ? 0: res; // In case adding duplicates lead to negative sum 
    }
}