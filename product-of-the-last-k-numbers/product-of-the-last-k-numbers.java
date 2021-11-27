class ProductOfNumbers {

    // holds cumulative product val
    private List<Integer> list;
    
    public ProductOfNumbers() {
        this.list = new ArrayList<>();
    }
    
    public void add(int num) {
        
        if(num == 0) {
            this.list.clear();
            return;
        }
        
        int prev = (list.size() >= 1) ? list.get(list.size() - 1) : 1;
        list.add(num*prev);
        // System.out.println(this.list);
    }
    
    public int getProduct(int k) {
        int n = list.size() - 1;
        int last = list.get(n);
        
        if(n + 1 == k) {
            return last;
        }
        
        if(n-k < 0) {
            return 0;
        }
        
        
        int val = list.get(n - k);
        
        return last/val;
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */