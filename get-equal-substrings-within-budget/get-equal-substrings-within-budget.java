class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int windowStart = 0,
            windowEnd = 0,
            windowCost = 0,
            maxWindowSize = 0;
        while (windowEnd < s.length()) {
            int sCharCodeToAdd = s.charAt(windowEnd),
                tCharCodeToAdd = t.charAt(windowEnd);
            windowEnd++;
            windowCost += Math.abs(sCharCodeToAdd - tCharCodeToAdd);
            while (windowCost > maxCost) {
                int sCharCodeToSubtract = s.charAt(windowStart),
                    tCharCodeToSubtract = t.charAt(windowStart);
                windowStart++;
                windowCost -= Math.abs(sCharCodeToSubtract - tCharCodeToSubtract);
            }
            maxWindowSize = Math.max(maxWindowSize, windowEnd - windowStart);
        }
        return maxWindowSize;
    }
}