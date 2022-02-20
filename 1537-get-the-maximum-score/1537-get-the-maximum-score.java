//java dp

class Solution {
    public int maxSum(int[] nums1, int[] nums2) {
        long dp1[]=new long[nums1.length+1];
        long dp2[]=new long[nums2.length+1];
        HashMap<Integer,Integer>map=new HashMap<Integer,Integer>();
        for(int i=nums2.length-1;i>=0;i--)
            map.put(nums2[i],i);
        int index=nums2.length-1;
        dp1[nums1.length-1]=nums1[nums1.length-1];
        dp2[nums2.length-1]=nums2[nums2.length-1];
        for(int i=nums1.length-2;i>=0;i--)
        {
            dp1[i]=nums1[i]+dp1[i+1];
            if(map.containsKey(nums1[i]))
            {
                int x=map.get(nums1[i]);
                for(int j=index;j>=x;j--)
                {
                    dp2[j]=Math.max(dp2[j],nums2[j]+dp2[j+1]);
                }
                long max=Math.max(dp1[i],dp2[x]);
                dp1[i]=max;
                dp2[x]=max;
                index=x-1;
            }
        }
        while(index>=0)
        {
            dp2[index]=nums2[index]+dp2[index+1];
            index--;
        }
        return (int)(Math.max(dp1[0],dp2[0])%1000000007);
    }
}