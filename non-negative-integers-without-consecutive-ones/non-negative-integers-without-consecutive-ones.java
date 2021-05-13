class Solution {
    public int findIntegers(int num) {
        int cnt = 0;
        int[] dp1 = new int[32];
        int[] dp2 = new int[32];
        dp1[0] = 1;
        dp2[0] = 1;
        for(int i= 1; i<32; i++){
            dp1[i] = dp1[i-1] + dp2[i-1];
            dp2[i] = dp1[i-1];
        }
        int bit = 0;
        int i = 30;
		int sum = 0;
		int prev= 0;
        while (i >= 0) {
            if ((num & (1 << i)) != 0) {
                sum += dp1[i];
                if (prev == 1) {
                    sum--;
                    break;
                }
                prev = 1;
            } else
                prev = 0;
            i--;
        } 
        return sum+1;
    }
}