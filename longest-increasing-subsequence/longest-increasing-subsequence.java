class Solution {
    public int lengthOfLIS(int[] nums) {
        List<Integer> arr = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int l = 0, r = arr.size();
            while (l < r) {
                int m = l + (r - l) / 2;
                if (arr.get(m) < nums[i]) l = m + 1;
                else r = m;
            }
            if (l == arr.size()) arr.add(nums[i]);
            else arr.set(l, nums[i]);
        }
        return arr.size();
    }
}