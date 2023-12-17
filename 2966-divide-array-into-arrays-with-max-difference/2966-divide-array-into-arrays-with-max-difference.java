class Solution {
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        int[][] arr = new int[nums.length / 3][3];
        for (int i = 2; i < nums.length; i += 3) {
            int a = nums[i - 2], b = nums[i - 1], c = nums[i];
            if (c - a > k) {
                return new int[0][0];
            }
            int idx = i / 3;
            arr[idx][0] = a;
            arr[idx][1] = b;
            arr[idx][2] = c;
        }
        return arr;
    }
}