class Solution {
    public boolean primeSubOperation(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if (checkSort(nums)) {
                return true;
            }
            int n = (i == 0) ? nums[0] : nums[i] - nums[i - 1];
            if (n <= 0) {
                return false;
            }
            nums[i] -= getLessPrime(n);
        }
        return checkSort(nums);
    }

    boolean checkSort(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
        }
        return true;
    }

    int getLessPrime(int n) {
        n--;
        while (n > 1 && !isPrime(n)) {
            n--;
        }
        return n > 1 ? n : 0;
    }

    boolean isPrime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}