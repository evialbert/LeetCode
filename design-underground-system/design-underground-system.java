class UndergroundSystem {

    Map<Integer, Stack<StationTime>> map;
    Map<String, Map<String, Timer>> timeMap;
    
    public UndergroundSystem() {

        this.map = new HashMap<>();
        this.timeMap = new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
        
        map.putIfAbsent(id, new Stack<>());
        StationTime st = new StationTime(stationName, t);
        map.get(id).push(st);
    }
    
    public void checkOut(int id, String stationName, int t) {
        
        Stack<StationTime> stack = map.get(id);
        StationTime start = stack.pop();
        
        String startStation = start.stationName;
        int startTime = start.t;
        
        timeMap.putIfAbsent(startStation, new HashMap<>());
        timeMap.get(startStation).putIfAbsent(stationName, new Timer(0, 0));
        
        Timer timer = timeMap.get(startStation).get(stationName);
        timer.count = timer.count + 1;
        timer.time = timer.time + t - startTime;
    }
    
    public double getAverageTime(String startStation, String endStation) {
        
        Timer timer = timeMap.get(startStation).get(endStation);
        
        return 1.0 * timer.time / timer.count;
    }
    
    class Timer {
        int count;
        int time;
        
        public Timer (int count, int time) {
            this.count = count;
            this.time = time;
        }
    }
    
    class StationTime {
        
        String stationName;
        int t;
        
        public StationTime(String stationName, int t) {
            this.stationName = stationName;
            this.t = t;
        }
        
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */