class Solution {
    Map<Integer, Integer> map = new HashMap<>(); // <Index, Value>
    public int tribonacci(int n) {
        // corner cases:
        if (n <= 1) return n;
        if (n == 2) return 1;
        
        // initialize the memorization
        map.put(0,0);
        map.put(1,1);
        map.put(2,1);
        
        return helper(n);
    }
    
    /**
    * Recursion helper function
    */
    private int helper(int n) {
        if (map.containsKey(n)) return map.get(n);
        
        map.put(n, helper(n-1) + helper(n-2) + helper(n-3));
        return map.get(n);
    }
}