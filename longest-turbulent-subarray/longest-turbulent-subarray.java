class Solution {
    public int maxTurbulenceSize(int[] A) {
        int n = A.length;
        if(n < 2)
            return n;
        int prevdiff = A[1] - A[0];
        int cur = (prevdiff == 0) ? 1 : 2;
        int max = cur;
        for(int i = 2; i < n; i++) {
            int diff = A[i] - A[i - 1];
            if((diff < 0 && prevdiff > 0) || (diff > 0 && prevdiff < 0)) {
                cur++;
                max = Math.max(max, cur);
            }
            else {
                cur = (diff == 0) ? 1 : 2;
            }
            prevdiff = diff;
        }
        return max;
    }
}