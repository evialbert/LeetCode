class Solution {
    public int maximumPossibleSize(int[] nums) {
        int naa = nums.length, coon = 0, icc = 0;
        while (icc < naa) {
            int maxdf = nums[icc], jcc = icc + 1;
            while (jcc < naa && nums[jcc] < maxdf) {
                maxdf = Math.max(maxdf, nums[jcc]);
                jcc++;
            }
            coon++;
            icc = jcc;
        }
        return coon;
    }
}