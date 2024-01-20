class Solution {
    public int sumSubarrayMins(int[] arr) {
        int[] lm = new int[arr.length];
        Stack<Integer> s = new Stack<>();
        for(int i=0;i<arr.length;i++){
            while(s.size()!=0 && arr[s.peek()]>arr[i]) s.pop();
            if(s.size() == 0)
                lm[i] = -1;
            else
                lm[i] = s.peek();
            s.push(i);
        }
        int res = 0,mod = 1000000007;
        int dp[] = new int[arr.length];
        for(int i=0;i<arr.length;i++){
            if(lm[i] == -1)
                dp[i] = (arr[i]*(i+1))%mod;
            else{
                dp[i] = (arr[i]*(i-lm[i]))%mod;
                dp[i] += dp[lm[i]];
            }
            res = (res+dp[i])%mod;
        }
        return res;
    }
}