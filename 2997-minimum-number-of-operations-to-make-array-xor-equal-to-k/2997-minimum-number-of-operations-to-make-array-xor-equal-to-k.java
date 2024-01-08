class Solution {
    public int minOperations(int[] nums, int k) {
        int changeRequired = 0;
        int x = 0;
        for(int num: nums) {
            x^=num;
        }
        while(k!=0 || x!=0) {
            changeRequired += (k&1) == (x&1) ? 0 : 1;
            k>>=1;
            x>>=1;
        }
        return changeRequired;
    }
}