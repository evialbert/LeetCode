class Solution {
    int sum;
    List<Integer> rgs;
    Set<Integer> key;
    public Solution(int[] w) {
        this.sum = Arrays.stream(w).sum();
        this.rgs = new ArrayList<Integer>();
        int presum = 0;
        
        for(int i=0; i<w.length; i++){
            this.rgs.add(presum);
            presum += w[i];
        }
    }
    
    public int pickIndex() {
        int rnd = (int)(Math.random()*(this.sum));
        int l = 0, r = this.rgs.size();
        
        while(l+1<r){
            int mid = l + (r-l)/2;
            if(this.rgs.get(mid)==rnd){
                return mid;
            }else if(this.rgs.get(mid)>rnd){
                r = mid;
            }else if(this.rgs.get(mid)<rnd){
                l = mid;
            }
        }
        return l;
    }
}
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */