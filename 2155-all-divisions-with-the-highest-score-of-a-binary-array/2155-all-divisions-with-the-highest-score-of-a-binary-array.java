class Solution {
    public List<Integer> maxScoreIndices(int[] nums) {
        int n=nums.length;
        List<Integer> ans=new LinkedList<>();
        int sum=0,max=0;
        for(int x:nums)
        {
            sum+=x;
        }
        max=Math.max(max,sum);
        max=Math.max(max,n-sum);
        int i=1;
        while(i<n)
        {
            
            int noOfOnes=sum-nums[i-1];
            int noOfZeroes=i-nums[i-1];
            max=Math.max(max,noOfZeroes+noOfOnes);
            nums[i]=nums[i-1]+nums[i];
            ++i;
        }
        i=1;
        while(i<n)
        {
            int noOfOnes=sum-nums[i-1];
            int noOfZeroes=i-nums[i-1];
            if(max==noOfZeroes+noOfOnes)
                ans.add(i);
            ++i;
        }
        if(max==sum)
            ans.add(0);
        if(max==n-sum)
            ans.add(n);
        
        return ans;
    }
}