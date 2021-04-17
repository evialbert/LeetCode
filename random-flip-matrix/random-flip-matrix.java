class Solution {
    
    private int rows, cols, total;
    private Random rand;
    private Set<Integer> available; // this contains a set of coordinates that we could set to one

    public Solution(int n_rows, int n_cols) {
        this.rows = n_rows;
        this.cols = n_cols;
        this.rand = new Random();
        this.available = new HashSet<>();
        this.total = this.rows * this.cols;
    }
    
    public int[] flip() {
        int x = rand.nextInt(this.total);
        
        // keep grabbing random numbers until we find one that isn't in there
        while (available.contains(x)) {
            x = rand.nextInt(this.total);
        }
        
        this.available.add(x);
        return new int[]{x / this.cols, x % this.cols};
    }
    
    public void reset() {
        this.available.clear();
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * int[] param_1 = obj.flip();
 * obj.reset();
 */