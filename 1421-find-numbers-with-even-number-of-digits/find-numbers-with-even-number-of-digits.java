class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
        for(int num : nums) {
            if(isValid(num))
            count++;
        }
        return count;
    }
    private boolean isValid(int num) {
        int count = 0;
        while(num > 0) {
            count++;
            num /= 10;
        }
        return count % 2 == 0;
    }
}