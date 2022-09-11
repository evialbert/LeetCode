class RangeFreqQuery {
    Map<Integer, ArrayList<Integer>> map;
    
    public RangeFreqQuery(int[] arr) {
        // sorted list of indices per value
        map= new HashMap<>();
        int n= arr.length;
        for(int i=0; i<n; i++){
            ArrayList<Integer> idxs= map.get(arr[i]);
            if(idxs==null) map.put(arr[i], idxs= new ArrayList<>());
            idxs.add(i);
        }
    }
    
    public int query(int left, int right, int value) {
        ArrayList<Integer> idxs= map.get(value);
        if(idxs==null) return 0;
        int l= Collections.binarySearch(idxs, left);
        if(l<0) l= -l-1; // if left not present among indices, return its insertion index (in array of indices)
        int r= Collections.binarySearch(idxs, right);
        if(r<0) r= -r-2; // if right not present among indices, return its insertion index-1
        return r-l+1; // count of indices in range <l,r>
    }
}
/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery obj = new RangeFreqQuery(arr);
 * int param_1 = obj.query(left,right,value);
 */