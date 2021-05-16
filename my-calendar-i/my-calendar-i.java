class MyCalendar {

    private TreeMap<Integer,Integer> intervals = new TreeMap<>();
    
    public MyCalendar() {}
    
    public boolean book(int start, int end) {
        if (intervals.containsKey(start)) return false;

        var lowerEntry = intervals.lowerEntry(start);
        var higherEntry = intervals.higherEntry(start);
        
        if ( (lowerEntry == null || start >= lowerEntry.getValue())
             && (higherEntry == null || end <= higherEntry.getKey()) ) {
            
            intervals.put(start,end);
            return true;
        }
        return false;        
    }
}
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */