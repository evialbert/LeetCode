class Solution {

    public boolean checkPossibility(int[] nums) {

        if (nums == null || nums.length <= 2) return true;

        int len = nums.length;

        int cnt = 1;

        for (int i = 1; i < len; i++) {

            if (nums[i] >= nums[i - 1]) continue;

            else if (cnt > 0) {

                cnt--;

                int min = Math.min(nums[i], nums[i - 1]);

                if (i >= 2 && min >= nums[i - 2]) {

                    nums[i] = min;

                } else if (i >= 2 && min < nums[i - 2]) {

                    nums[i] = Math.max(nums[i], nums[i - 1]);

                }

                continue;

            }

            return false;

        }

        

        return true;

    }

}