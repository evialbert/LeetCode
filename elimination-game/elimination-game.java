class Solution {
    public int lastRemaining(int n) {
        return helper(n, 0);
    }
    
    public int helper(int n, int direction) {
        if (n == 1)
            return 1;

        if (direction == 0)
            return 2 * helper(n / 2, 1);
        
        return 2 * helper(n / 2, 0) + n%2 - 1;
    }
}