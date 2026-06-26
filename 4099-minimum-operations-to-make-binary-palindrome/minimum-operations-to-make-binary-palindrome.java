class Solution {
    private int binlen(int n){
        int c = 0;
        while(n > 0) {
            c++;
            n >>= 1;
        }
        return c;
    }
    private boolean isPal(int n) {
        int l = 0, r = binlen(n) - 1;
        while(l < r) {
            if(((n >> l) & 1) != ((n >> r) & 1)) return false;
            l++;
            r--;
        }
        return true;
    }
    public int[] minOperations(int[] nums) {
        boolean[] binary = new boolean[5050];
        int[] ans = new int[nums.length];
        for(int i = 0; i < 5050; i++) binary[i] = isPal(i);
        for(int i = 0; i < nums.length; i++) {
            int a = nums[i], b = nums[i], c1 = 0, c2 = 0;
            while(binary[a] == false) {
                a--;
                c1++;
            } 
            while(binary[b] == false) {
                b++;
                c2++;
            }
            ans[i] = Math.min(c1,c2);
        }
        return ans;
    }
}