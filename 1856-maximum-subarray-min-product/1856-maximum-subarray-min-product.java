class Solution {
    public int maxSumMinProduct(int[] nums) {
        int n=nums.length;
        long mod = 1000000007;
        long[] sum = new long[n];
        sum[0]=nums[0];
        Stack<Integer>st = new Stack<>();
        for(int i=1;i<n;i++)
        {
            sum[i]=sum[i-1]+nums[i];
        }
        long ans=0;
        for(int i=0;i<n;i++)
        {
            if(st.isEmpty())
            {
                st.push(i);
            }
            else
            {
                while(!st.isEmpty() && nums[st.peek()] >=nums[i] )
                {
                    int top = st.pop();
                    if(st.isEmpty())
                    {
                        ans = Math.max(ans, sum[i-1]*nums[top]);
                    }
                    else
                    {
                        ans = Math.max(ans,( sum[i-1] - sum[st.peek()]) * nums[top] );
                    }
                }
                st.push(i);
            }
        }
        while(!st.isEmpty()){
            int top = st.pop();
            if(st.isEmpty()){
                ans = Math.max(ans, sum[n-1]*nums[top]);
            }else{
                ans = Math.max(ans, (sum[n-1] - sum[st.peek()])*nums[top]);
            }
        }
        
        return (int)(ans % mod);
    }
}