class MyCalendarThree {
    TreeMap<Integer,Integer> treeMap;
    int max;
    public MyCalendarThree() {
        treeMap = new TreeMap<>();
        treeMap.put(-1,0);
        max = 0;
    }
    
    public int book(int start, int end) {
        treeMap.put(start,treeMap.getOrDefault(start,0)+1);
        treeMap.put(end,treeMap.getOrDefault(end,0)-1);
        
        int sum = 0;
        for(int d:treeMap.subMap(treeMap.firstKey(),end).keySet()) {
            sum += treeMap.get(d);
            max = Math.max(max,sum);
        }
        return max;
    }
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */