class KthLargest {
    private int[] l;
    private int k;
    public KthLargest(int k, int[] nums) {
        l=nums;
        this.k=k;
    }
    
    public int add(int val) {
        l=Arrays.copyOf(l,l.length+1);
        l[l.length-1]=val;
        Arrays.sort(l);
        return l[l.length-k];
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */