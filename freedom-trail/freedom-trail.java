class Solution {
    
    Integer[][][] memo;
    public int findRotateSteps(String ring, String key) {
        memo = new Integer[ring.length()][key.length()][2];
        return Math.min(rotate(ring, key, 0, 0, -1), rotate(ring, key, 0,  0, 1));
    }
    
    private int rotate(String ring, String key, int ringIdx, int pos, int dir) {
        if (pos == key.length())
            return 0;
        // 1 step to press button
        if (ring.charAt(ringIdx) == key.charAt(pos)) {
            return 1 + Math.min(rotate(ring, key, ringIdx, pos + 1, -1), rotate(ring, key, ringIdx, pos + 1, 1));
        }
        if (memo[ringIdx][pos][dir == -1 ? 0 : 1] != null)
            return memo[ringIdx][pos][dir == -1 ? 0 : 1];
        
        char c = key.charAt(pos);
        int dist = 0;
        int newRingIdx = ringIdx;
        if (dir == 1) {
            // rotating clockwise
            while (ring.charAt(newRingIdx) != c) {
                newRingIdx++;
                dist++;
                newRingIdx = newRingIdx % ring.length();
            }
        }
        else {
            // rotating counterclockwise
            while (ring.charAt(newRingIdx) != c) {
                newRingIdx--;
                dist++;
                if (newRingIdx < 0)
                    newRingIdx+= ring.length();
            }
            
        }
        int val = dist + Math.min(rotate(ring, key, newRingIdx, pos, -1), rotate(ring, key, newRingIdx, pos, 1));
        memo[ringIdx][pos][dir == -1 ? 0 : 1] = val;
        return val;
    }
}