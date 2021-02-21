class Solution {
    public boolean validMountainArray(int[] A) {
        if (A == null || A.length < 3) {
            return false;
        }
        int peak = 0;
        while (peak + 1 < A.length) {
            if (A[peak + 1] <= A[peak]) {
                break;
            }
            peak++;
        }
        if (peak == 0 || peak == A.length - 1) {
            return false;
        }
        while (peak + 1 < A.length) {
            if (A[peak] <= A[peak + 1]) {
                return false;
            }
            peak++;
        }
        return true;
    }
}