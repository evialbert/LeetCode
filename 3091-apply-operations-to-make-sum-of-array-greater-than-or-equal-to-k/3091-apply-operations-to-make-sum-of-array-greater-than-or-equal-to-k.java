class Solution {
    public int minOperations(int k) {
        if (k == 1) return 0;
        int min = 0;
        int res = Integer.MAX_VALUE; // Operation times;
        for (int i = 1; i < k; i++) {
            int cal = i - 1;
            if (k % i != 0) {
                cal += (k / i) + 1 - 1;
            } else {
                cal += (k / i) - 1;
            }
            res = Math.min(res, cal);
            if (cal > res) {
                break;
            }
        }
        return res;
    }
}