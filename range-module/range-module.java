class RangeModule {

    Queue<int[]> q = new LinkedList<>();

    public RangeModule() {
        
    }
    
    public void addRange(int left, int right) {
        int[] add = new int[]{left, right};
        int sz = q.size();
        for(int i=0; i<sz; i++){
            int[] n = q.poll();
            if(add[0]<n[0] && add[1]<n[0] || add[0]>n[1] && add[1]>n[1]) q.offer(n);
            else add = new int[]{Math.min(add[0], n[0]), Math.max(add[1], n[1])};
        }
        q.offer(add);
    }
    
    public boolean queryRange(int left, int right) {
        return q.stream().anyMatch(n->n[0]<=left && n[1]>=right);
    }
    
    public void removeRange(int left, int right) {
        int sz = q.size();
        for(int i=0; i<sz; i++){
            int[] n = q.poll();
            if(n[0]<left && n[1]<=left || n[0]>=right && n[1]>right) q.offer(n);
            else{
                if(n[0]<left)  q.offer(new int[]{n[0], left});
                if(n[1]>right) q.offer(new int[]{right, n[1]});
            }
        }
    }
}