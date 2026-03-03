class Solution {
    public int minAllOneMultiple(int k) {
        // Case 1: Impossible factors
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        int rem = 0;

        // Case 2: Modular Simulation
        for (int oneLen = 1; oneLen <= k; oneLen++) {
            rem = (rem * 10 + 1) % k;

            if (rem == 0) {
                return oneLen;
            }
        }
        return -1;
    }
}