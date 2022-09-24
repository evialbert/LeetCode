class SORTracker {
    class Location {
        String name;
        int score;
        public Location(String name, int score) {
            this.name = name;
            this.score = score;
        }
        public String getName() {
            return name;
        }
        public int getScore() {
            return score;
        }
    }
    
    TreeSet<Location> tSet1;
    TreeSet<Location> tSet2;

    public SORTracker() {
        tSet1 = new TreeSet<Location>((a,b)->{
            if (a.score != b.score) {
                return b.getScore() - a.getScore();
            } else {
                return a.getName().compareTo(b.getName());
            }
        });
        
        tSet2 = new TreeSet<Location>((a,b)->{
            if (a.score != b.score) {
                return b.getScore() - a.getScore();
            } else {
                return a.getName().compareTo(b.getName());
            }
        });
        
        
    }
    
    public void add(String name, int score) {
        tSet1.add(new Location(name, score));
        tSet2.add(tSet1.pollLast());
    }
    
    public String get() {
        Location res = tSet2.pollFirst();
        tSet1.add(res);
        return res.name;
    }
}
/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker obj = new SORTracker();
 * obj.add(name,score);
 * String param_2 = obj.get();
 */