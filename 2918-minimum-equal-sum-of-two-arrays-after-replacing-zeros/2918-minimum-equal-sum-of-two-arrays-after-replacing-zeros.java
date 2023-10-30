class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long sum1=0;
        long sum2=0;
        int zeros1=0;
        int zeros2=0;
        for (int i : nums1) {
            sum1+=i;
            if (i==0) {
                zeros1++;
            }
        }
        for (int i : nums2) {
            sum2+=i;
            if (i==0) {
                zeros2++;
            }
        }
        sum1+=zeros1;
        sum2+=zeros2;
        if (sum1==sum2) return sum1;
        if (sum1<sum2 && zeros1>0) return sum2;
        else if (sum1>sum2 && zeros2>0) return sum1;
        return -1;
            
        
        
    }
}