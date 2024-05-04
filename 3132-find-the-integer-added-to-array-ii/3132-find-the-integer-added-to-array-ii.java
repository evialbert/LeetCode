class Solution {
    public int minimumAddedInteger(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        int min = 2000;
        for(int i=0;i<=2;i++){
            int skip = i;
            int diff = nums2[0] - nums1[i];
            int k = 0;
            for(int j=i;j<nums1.length;j++){
                if((nums2[k] - nums1[j]) != diff && skip == 2)break;
                if((nums2[k] - nums1[j]) != diff){
                    skip++;
                }else{
                    k++;
                }
                if(k == nums2.length)break;
            }
            if(k == nums2.length){
                min = Math.min(min,diff);      
            }
        }
        return min == 2000?0:min;
    }
}