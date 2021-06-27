class Solution {
        public int bestRotation(int[] A) {
            int LEN = A.length;
            int score, ans, ansInd, k; score = k = ans = ansInd = 0;
            for(int i = 0; i < LEN; i++) A[i] -= i;
            int[] bit = new int[3 * LEN + 1];
            for(int i = k; i < LEN; i++) bitAdd(bit, 3 * LEN + 1, vToIndex(A[i], LEN), 1);
            while (k < LEN) {
                score = bitPreSum(bit, vToIndex(-k, LEN));
                if(score > ans) {
                    ansInd = k;
                    ans = score;
                }
                bitAdd(bit, 3 * LEN + 1, vToIndex(A[k], LEN), -1);
                bitAdd(bit, 3 * LEN + 1, vToIndex(A[k] - LEN, LEN), 1);
                k++;
            }
            return ansInd;
        }
    
        void bitAdd(int[] bit, int bLEN, int ind, int delta) {
            for(; ind < bLEN; ind = (ind | (ind + 1))) {
                bit[ind] += delta;
            }
        }

        int bitPreSum(int[] bit, int ind) {
            int ans = 0;
            for(; ind >= 0; ind = (ind & (ind + 1)) - 1) {
                ans += bit[ind];
            }
            return ans;
        }
        
        int vToIndex(int v, int LEN) {
            return v + 2 * LEN;
        }
}