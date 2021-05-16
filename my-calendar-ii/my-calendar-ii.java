class MyCalendarTwo {
    
    // double booking intersection, we will check new booking if it overlaps with double booking
    List<int[]> intersect;
    // store booking so that we can calculate intersection and add it to double booking
    List<int[]> single;

    public MyCalendarTwo() {
        this.intersect = new ArrayList<>();
        this.single = new ArrayList<>();
    }
    
    public boolean book(int start, int end) {
        // 1. check for double booking
        for (int[] overlap: intersect) {
            if (overlap[0] < end && start < overlap[1]) { // s1 < e2 && s2 < e1 -> intersection is Max(s1,s2), Min(e1,e1)
                // it is a double booking
                return false;
            }
        }
        for (int[] event: single) {
            if (event[0] < end && start < event[1]) { // s1 < e2 && s2 < e1 -> intersection is Max(s1,s2), Min(e1,e1)
                // it intersects, calculate intersection
                intersect.add(new int[]{Math.max(start, event[0]), Math.min(end, event[1])});
            }
        }
        // add to calendar
        single.add(new int[]{start, end});
        return true;
    }
}