class SummaryRanges {
    private List<int[]> list;

    /** Initialize your data structure here. */
    public SummaryRanges() {
        list = new ArrayList<>();
    }
    
    public void addNum(int val) {
        int[] cur = new int[]{val, val};
        List<int[]> tmp = new ArrayList<>();
        for(int[] next : list) {
            if(next[1] < cur[0] - 1) {
                tmp.add(next);
            } else if (next[0] > cur[1] + 1) {
                tmp.add(cur);
                cur = next;
            } else {
                cur[0] = Math.min(next[0], cur[0]);
                cur[1] = Math.max(next[1], cur[1]);
            }
        }
        tmp.add(cur);
        list = tmp;
    }
    
    public int[][] getIntervals() {
        return list.toArray(new int[list.size()][]);
    }
}