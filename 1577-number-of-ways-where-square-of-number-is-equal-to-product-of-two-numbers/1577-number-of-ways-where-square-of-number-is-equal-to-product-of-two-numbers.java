class Solution {
    public int helper(int[] ar1, int[] ar2){
        int res = 0;
        int n = ar2.length;
        
        for(long num : ar1){
            int l = 0;
            int r = n-1;
            
            while(l < r){
                long val1 = ar2[l];
                long val2 = ar2[r];
                
                if( val1 == val2){
				    //          l        r
                    //          |        |
                    // [..., 1, 2, 2, 2, 2, 4,....]
                    res += val1*val2 == num*num ? (r-l)*(r-l+1)/2 : 0;
                    break;    
                }
                
                if(num*num == val1*val2){
                    int count1 = 0;
                    while( l < r && ar2[l] == val1){
                        count1++;
                        l++;
                    }
                    while( ar2[r] == val2){
                        res += count1;
                        r--;
                    }
                }
                else if( val1*val2 > num*num){
                    while( l < r && ar2[r] == val2)
                        r--;
                }
                else{
                    while( l < r && ar2[l] == val1)
                        l++;
                }
            }
        }
        return res;
    }
    
    public int numTriplets(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        return helper(nums1, nums2) + helper(nums2, nums1); 
    }
}