class Solution {
    public int minElement(int[] nums) {
        int min = Integer.MAX_VALUE;
        for (int item : nums) {
            min = Math.min(helper(item),min);

        }
        return min;
    }
    public int helper (int num) {
        int sum = 0;
        while(num>=10) {
            sum += num%10;
            num = num/10;
        }
        sum+=num%10;
        return sum;
    }
}