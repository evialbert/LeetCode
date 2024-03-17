class Solution {
    public int sumOfEncryptedInt(int[] nums) {
        int sum = 0;
        for(int num : nums) {
            if(num < 10) {
                sum += num;
            } else {
                sum += replaceEveryDigitWithMaxDigit(num);
            }
        }
        return sum;
    }

    private int replaceEveryDigitWithMaxDigit(int n) {
        int num = n, maxDigit = 0, multiplier = 0;
        
        while(num != 0) {
            int digit = num % 10;
            maxDigit = Math.max(digit, maxDigit);
            multiplier = (multiplier * 10) + 1;
            num /= 10;
        }

        return multiplier * maxDigit;
    }
}