class Solution {
    public int repeatedNTimes(int[] A) {
        Set<Integer> seenNumbers = new HashSet<>();
        for (int num : A) {
            if (seenNumbers.contains(num)) {
                return num;
            }
            seenNumbers.add(num);
        }
        // Should not be reached
        return 0;
    }
}