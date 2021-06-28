class Solution {
    public boolean splitArraySameAverage(int[] A) {
        double sum = getSum(A);
        for (int i = 1; i < A.length / 2 + 1; i++) {
            // select i elements to reach target - C(i, n)
            if ((sum / A.length) * i - (int) ((sum / A.length) * i) > 0.001) {
                continue;
            }
            int target = (int) ((sum / A.length) * i);
            if (backtrack(A, target, i, 0)) {
                return true;
            }
        }
        return false;
    }
    
    private boolean backtrack(int[] A, double target, int k, int start) {
        if (k == 0 && target == 0) {
            return true;
        }
        if (k == 0)
            return false;
        
        for (int i = start; i < A.length; i++) {

            if (backtrack(A, target - (double) A[i], k - 1, i + 1))
                return true;
            while (i != A.length - 1 && A[i] == A[i + 1])
                i++;
        }
        return false;
    }
    /* 
    * method for calculating total sum of input array
    */
    private double getSum(int[] A) {
        double res = 0;
        for (int i : A) {
            res += i;
        }
        return res;
    }
}