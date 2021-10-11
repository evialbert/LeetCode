class MajorityChecker {

    int[] data;
    
    public MajorityChecker(int[] arr) {
        data = arr;
    }
    
    public int query(int left, int right, int threshold) {
        int[] d = new int[data.length+1];
        for(int i=left; i<=right; i++)
            if((d[data.length]=Math.max(++d[data[i]], d[data.length]))==threshold) return data[i];
        return -1;
    }
}

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker obj = new MajorityChecker(arr);
 * int param_1 = obj.query(left,right,threshold);
 */