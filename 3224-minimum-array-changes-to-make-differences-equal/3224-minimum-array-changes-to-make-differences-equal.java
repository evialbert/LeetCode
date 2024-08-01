class Solution {
    public int minChanges(int[] nums, int k) {
        int[] diff = new int[k + 2];
        int n = nums.length;
        int left = 0, right = n -1;
        while(left < right){
            int num1 = nums[left++];
            int num2 = nums[right--];
            int min = Math.min(num1, num2);
            int max = Math.max(num1, num2);
            int x = max - min;
            max = Math.max(max, k - min);
            diff[0]++;
            diff[x]--;
            diff[x + 1]++;
            diff[max + 1]++;
        }
        int count = n;
        int sum = 0;
        for(int d : diff){
            sum += d;
            count = Math.min(count, sum);
        }
        return count;
    }
}