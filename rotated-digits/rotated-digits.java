class Solution {
    public int rotatedDigits(int N) {
        int ret = 0;
        for (int i = 1; i <= N; i++) {
            if (isValid(i)) ret++;
        }
        
        return ret;
    }
    
    private boolean isValid(int num) {
        boolean valid = false;
        while (num > 0) {
            int d = num % 10;
            if (d == 3 || d == 4 || d == 7) return false;
            if (d == 2 || d == 5 || d == 6 || d == 9) valid = true;
            num = num / 10;
        }
        
        return valid;
    }

}