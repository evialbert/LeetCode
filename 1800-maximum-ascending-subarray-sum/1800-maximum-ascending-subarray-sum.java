class Solution {
    public int maxAscendingSum(int[] nums) {
        int max=Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++)
        {
            int sum=nums[i];
            for(int j=i;j<nums.length-1;j++)
            {
                if(nums[j+1]>nums[j])
                {
                    sum+=nums[j+1];
                }
                else
                {
                    break;
                }
            }
            max=sum>max?sum:max;
        }
        return max;
    }
}