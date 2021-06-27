class Solution {
    public int minSwap(int[] A, int[] B) {
        int l = A == null ? 0 : A.length;
        if (l == 0) {
            return 0;
        }
        int preSwap = 1;
        int preNotSwap = 0;
        for(int i = 1; i < l; ++i) {
            int nextSwap = A[i] <= B[i - 1] || B[i] <= A[i - 1] ? preSwap + 1 : Math.min(preNotSwap + 1, B[i] <= B[i - 1] || A[i] <= A[i - 1] ? Integer.MAX_VALUE : preSwap + 1);
            int nextNotSwap = B[i] <= B[i - 1] || A[i] <= A[i - 1] ? preSwap : Math.min(preNotSwap,  A[i] <= B[i - 1] || B[i] <= A[i - 1] ? Integer.MAX_VALUE : preSwap);
            preSwap = nextSwap;
            preNotSwap = nextNotSwap;
        }
        return Math.min(preSwap, preNotSwap);
    }
}