class Solution {
    Map<String, Double> memo;
    public double soupServings(int N) {
        if (N > 4800) return 1.0;
        
        this.memo = new HashMap<>();
        
        return serve(N, N);
    }
    
    private double serve(int A, int B) {
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;
        
        String key = A + "|" + B;
        // memoization
        if (memo.get(key) != null) return memo.get(key);
        
        double prob = 0.0;
        // remember to reduce the smaller amount in the operation
        prob += 0.25 * serve(A - Math.min(100, A), B);
        prob += 0.25 * serve(A - Math.min(75, A), B - Math.min(25, B));
        prob += 0.25 * serve(A - Math.min(50, A), B - Math.min(50, B));
        prob += 0.25 * serve(A - Math.min(25, A), B - Math.min(75, B));
        
		// store the intermediate results in the HashMap to save time
        memo.put(key, prob);
        
        return memo.get(key);
    }
}