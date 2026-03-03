class Solution {
public:
    char findKthBit(int n, int k) {
        bool flip = false; // whether we have inverted odd number of times

        while (n > 1) {
            int mid = 1 << (n - 1);      // 2^(n-1)
            int len = (1 << n) - 1;      // 2^n - 1

            if (k == mid) {
                // middle is always '1', but may be flipped
                return flip ? '0' : '1';
            }

            if (k > mid) {
                // go to mirrored position on left, and invert once
                k = len - k + 1;
                flip = !flip;
            }

            // now k is in left half -> corresponds to S_(n-1)
            n--;
        }

        // base S1 = "0"
        return flip ? '1' : '0';
    }
};