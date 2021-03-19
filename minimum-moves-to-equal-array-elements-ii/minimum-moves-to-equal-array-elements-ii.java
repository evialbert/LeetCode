class Solution {
public int minMoves2(int[] nums) {
     int m = nums.length;
    int res = 0;
    Arrays.sort(nums);
    int mid = nums[m/2];
     for (int i :nums) {
         res+=Math.abs(i-mid);
     }
     return res;
}
}