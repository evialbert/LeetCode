class Solution {
    public int minimumRecolors(String blocks, int k) {
        int currW = 0;

        // Count white blocks in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks.charAt(i) == 'W') {
                currW++;
            }
        }

        int minW = currW;
        int left = 0;

        // Sliding window
        for (int right = k; right < blocks.length(); right++) {
            if (currW == 0) return 0; // Already perfect window found

            if (blocks.charAt(left) == 'W') currW--;  // Remove the leftmost element
            if (blocks.charAt(right) == 'W') currW++; // Add the new rightmost element
            
            left++;
            minW = Math.min(minW, currW);
        }

        return minW;
    }
}