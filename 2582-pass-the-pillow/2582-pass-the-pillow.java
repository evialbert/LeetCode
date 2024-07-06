class Solution {
    public int passThePillow(int n, int time) {
        // Calculate the length of one complete cycle
        int cycleLength = (n - 1) * 2;
        
        // Find the current position within the cycle
        int positionInCycle = time % cycleLength;
        
        // Determine the position of the pillow based on the cycle position
        if (positionInCycle < n) {
            return positionInCycle + 1;
        } else {
            return cycleLength - positionInCycle + 1;
        }
    }
}