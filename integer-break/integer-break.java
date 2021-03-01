class Solution {
     public int integerBreak(int n) {
        // Observations
        // 6 < 2 x 2 x 2 < 3 x 3 (prefer 3,3 over 2,2,2 and 6)
        // 4 x 4 < 2 x 3 x 3 (prefer 2,3,3 over 4,4)
        // 5 < 2 x 3 (prefer 2,3 over 5)
        // In general, we want as many 3s as possible.
        // i.e. if n is divisible by 3, just use all 3s.
        // If n mod 3 = 1, use all 3s ending with a 4.
        // If n mod 3 = 2, use all 3s ending with a 2.
        
        // Base cases
        if (n == 2) return 1; // 1 + 1
        if (n == 3) return 2; // 2 + 1
        if (n == 4) return 4; // 2 + 2
        
        // Multiply our answer by 3, for each 3 we subtract from n.
        // When we get to n = 2, 3, or 4, multiply by that number and stop.
        int answer = 1;
        while (n > 4) { answer *= 3; n -= 3; }
        return answer * n;
    }
}