class Solution {
public:
    // Helper function to recursively find the k-th bit in Sn
    char findKthBit(int n, int k) {
        // Base case: S1 = "0"
        if (n == 1) return '0';
        
        // Length of the Sn string: length(Sn) = 2^n - 1
        int length = (1 << n) - 1;  // This is 2^n - 1
        
        int mid = length / 2 + 1;  // Middle position of Sn
        
        if (k == mid) {
            return '1';  // Middle element is always '1'
        } else if (k < mid) {
            return findKthBit(n - 1, k);  // If k is before the middle, find it in Sn-1
        } else {
            // If k is after the middle, find its mirrored position in Sn-1 and invert it
            int mirroredPos = length - k + 1;
            char mirroredBit = findKthBit(n - 1, mirroredPos);
            return mirroredBit == '0' ? '1' : '0';  // Invert the bit
        }
    }
};