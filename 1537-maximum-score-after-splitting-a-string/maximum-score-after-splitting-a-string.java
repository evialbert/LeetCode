class Solution {
    public int maxScore(String s) {
        int totalOnes = 0;
        // Count total number of ones in the string
        for (char c : s.toCharArray()) {
            if (c == '1') {
                totalOnes++;
            }
        }

        int maxScore = 0;
        int leftZeros = 0;
        int leftOnes = 0;

        // Iterate through the string to find the maximum score
        for (int i = 0; i < s.length() - 1; i++) { // We stop at length - 1 to ensure non-empty right substring
            if (s.charAt(i) == '0') {
                leftZeros++;
            } else {
                leftOnes++;
            }

            // Calculate the score for the current split
            int score = leftZeros + (totalOnes - leftOnes);
            maxScore = Math.max(maxScore, score);
        }

        return maxScore;
    }
}