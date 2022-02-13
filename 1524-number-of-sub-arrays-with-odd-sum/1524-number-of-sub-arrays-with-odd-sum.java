class Solution {
    public int numOfSubarrays(int[] arr) {
        int mod = (int)1e9 + 7;
        int len = arr.length;
        int[] dp_odd = new int[len];
        int[] dp_even = new int[len];
        if(arr[0] % 2 == 0) {
            dp_even[0] = 1;
        } else {
            dp_odd[0] = 1;
        }
        for(int i = 1; i < len; i++) {
            if(arr[i] % 2 == 0) {
                dp_odd[i] = dp_odd[i-1];
                dp_even[i] = (dp_even[i-1] + 1);
            } else {
                dp_even[i] = dp_odd[i-1];
                dp_odd[i]  = (dp_even[i-1] + 1);
            }
        }
        int sum = 0;
        for(int i = 0; i < len; i++) {
            sum = (sum + dp_odd[i]) % mod;
        }
        return sum;
    }
}