class Solution {
    public boolean xorGame(int[] nums) {
        int xor = 0, cnt = 0;
        for (int num : nums) xor ^= num;
        if (xor == 0) return true;
        while (true) {
            int tmp = cnt;
            for (int i = 0; i < nums.length; ++i) {
                if (nums[i] != -1 && (xor ^ nums[i]) != 0) {
                    xor ^= nums[i];
                    cnt++;
                    nums[i] = -1;
                }
            }
            if (tmp == cnt) break;
        }
        return cnt % 2 != 0;
    }
}